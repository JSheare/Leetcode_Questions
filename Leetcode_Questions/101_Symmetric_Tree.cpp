#include <iostream>
#include <assert.h>
#include <queue>

#include "TreeNode.h"
#include "BinaryTree.h"

// Iterative Solution
#if 0
bool isSymmetric(TreeNode* root)
{
    if (!root->left && !root->right)
        return true;

    if (!root->left || !root->right)
        return false;

    std::queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty())
    {
        int size{ static_cast<int>(q.size()) };
        if (size % 2 != 0)
            return false;

        size /= 2;
        while (size > 0)
        {
            TreeNode* leftNode{ q.front() };
            q.pop();
            TreeNode* rightNode{ q.front() };
            q.pop();
            if (!leftNode && !rightNode)
            {
                --size;
                continue;
            }
            if (!leftNode || !rightNode)
                return false;

            if (leftNode->val != rightNode->val)
                return false;

            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
            --size;
        }
    }
    return true;
}
#endif

// Recursive Solution
#if 1
bool isMirror(TreeNode* left, TreeNode* right)
{
    if (!left && !right)
        return true;

    if (!left || !right)
        return false;

    return ((left->val == right->val) &&
        isMirror(left->right, right->left) &&
        isMirror(left->left, right->right));
}

bool isSymmetric(TreeNode* root)
{
    if (!root->left && !root->right)
        return true;

    if (!root->left || !root->right)
        return false;

    return isMirror(root->left, root->right);
}
#endif

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "2", "2", "3", "4", "4", "3" };
    assert(isSymmetric(test1.root) == true);

    BinaryTree test2{ "1", "2", "2", "null", "3", "null", "3" };
    assert(isSymmetric(test2.root) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif