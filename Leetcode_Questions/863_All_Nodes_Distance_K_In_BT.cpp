#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

#include "TreeNode.h"
#include "BinaryTree.h"

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    if (k == 0)
        return { target->val };

    // Reconstructing the tree in graph form (adjacency list representation)
    std::vector<std::vector<int>> graph(501);
    std::queue<TreeNode*> gq;
    gq.push(root);
    while (!gq.empty())
    {
        TreeNode* node{ gq.front() };
        gq.pop();
        if (node->left)
        {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            gq.push(node->left);
        }
        if (node->right)
        {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            gq.push(node->right);
        }
    }
    // Doing a BFS up to the nodes k away from the target
    std::vector<int> visited(501, 0);
    std::queue<int> q;
    q.push(target->val);
    visited[target->val] = 1;
    int level{ 0 };
    while (!q.empty() && level < k)
    {
        int size{ static_cast<int>(q.size()) };
        for (int i{ 0 }; i < size; ++i)
        {
            int node{ q.front() };
            q.pop();
            for (auto& child : graph[node])
            {
                if (!visited[child])
                {
                    visited[child] = 1;
                    q.push(child);
                }
            }
        }
        ++level;
    }
    // Recording the nodes that are k away and returning them
    std::vector<int> kAway;
    while (!q.empty())
    {
        kAway.push_back(q.front());
        q.pop();
    }
    return kAway;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4" };
    std::vector<int> correct1{ 1, 7, 4 };
    assert(distanceK(test1.root, test1.findNode(5), 2) == correct1);

    BinaryTree test2{ "1" };
    std::vector<int> correct2{};
    assert(distanceK(test2.root, test2.findNode(1), 3) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif