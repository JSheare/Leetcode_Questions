#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <queue>

#include "TreeNode.h"
#include "BinaryTree.h"


// DFS approach
#if 0
void traverse(TreeNode* root, int level, std::unordered_set<int>& visited, std::vector<int>& view)
{
    if (!root)
        return;

    if (!visited.count(level))
    {
        view.push_back(root->val);
        visited.insert(level);
    }
    traverse(root->right, level + 1, visited, view);
    traverse(root->left, level + 1, visited, view);
}

std::vector<int> rightSideView(TreeNode* root)
{
    std::unordered_set<int> visited;
    std::vector<int> view;
    traverse(root, 0, visited, view);
    return view;
}
#endif

// BFS approach
#if 1
std::vector<int> rightSideView(TreeNode* root)
{
    if (!root)
        return {};

    std::vector<int> view;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        int level_size{ static_cast<int>(q.size()) };
        for (int i{ level_size }; i > 0; --i)
        {
            TreeNode* node{ q.front() };
            if (node)
            {
                if (i == level_size)
                    view.push_back(node->val);

                q.pop();
                if (node->right)
                    q.push(node->right);

                if (node->left)
                    q.push(node->left);
            }
        }
    }
    return view;
}
#endif

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "2", "3", "null", "5", "null", "4" };
    std::vector<int> correct1{ 1, 3, 4 };
    assert(rightSideView(test1.root) == correct1);

    BinaryTree test2{ "1", "null", "3" };
    std::vector<int> correct2{ 1, 3 };
    assert(rightSideView(test2.root) == correct2);

    BinaryTree test3{};
    std::vector<int> correct3;
    assert(rightSideView(test3.root) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif