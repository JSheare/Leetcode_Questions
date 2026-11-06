#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>

#include "TreeNode.h"
#include "BinaryTree.h"

// Recursive DFS solution
#if 0
int minDepth(TreeNode* root)
{
    if (!root)
        return 0;

    if (!root->left)
        return minDepth(root->right) + 1;
    else if (!root->right)
        return minDepth(root->left) + 1;

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}
#endif

// Iterative BFS solution
#if 1
int minDepth(TreeNode* root)
{
    if (!root)
        return 0;

    std::queue<TreeNode*> q;
    q.push(root);
    int currentMin{ 1 };
    while (!q.empty())
    {
        int qSize{ static_cast<int>(q.size()) };
        for (int i{ 0 }; i < qSize; ++i)
        {
            TreeNode* curr{ q.front() };
            q.pop();
            if (!curr->left && !curr->right)
                return currentMin;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
        ++currentMin;
    }
    return currentMin;
}
#endif

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "9", "20", "null", "null", "15", "7" };
    assert(minDepth(test1.root) == 2);

    BinaryTree test2{ "2", "null", "3", 
        "null", "null", "null", "4", "null", "null", "null", "null", "null", "null", "null", "5", 
        "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "null", "6" };
    assert(minDepth(test2.root) == 5);

    std::cout << "Success!\n";

    return 0;
}
#endif