#include <iostream>
#include <cassert>
#include <stack>

#include "TreeNode.h"
#include "BinaryTree.h"

// Recursive inorder traversal solution
#if 1
void inorderCount(TreeNode* root, int k, int& count, int& kSmall)
{
    if (!root)
        return;

    if (count == k)
        return;

    inorderCount(root->left, k, count, kSmall);
    ++count;
    if (count == k)
    {
        kSmall = root->val;
        return;
    }
    inorderCount(root->right, k, count, kSmall);
}

int kthSmallest(TreeNode* root, int k)
{
    int count{ 0 };
    int kSmall{ -1 };
    inorderCount(root, k, count, kSmall);
    return kSmall;
}
#endif

// Iterative (stack) inorder traversal solution
#if 0
int kthSmallest(TreeNode* root, int k)
{
    std::stack<TreeNode*> s;
    int count{ 0 };
    TreeNode* node{ root };
    while (node || !s.empty())
    {
        // Traversing the left subtree as far as possible
        while (node)
        {
            s.push(node);
            node = node->left;
        }
        // Checking the current node
        if (!s.empty())
        {
            node = s.top();
            ++count;
            if (count == k)
                return node->val;

            s.pop();
            // Traversing the right subtree
            node = node->right;
        }

    }
    return -1;
}
#endif

#if 1
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "1", "4", "null", "2" };
    assert(kthSmallest(test1.root, 1) == 1);

    BinaryTree test2{ "5", "3", "6", "2", "4", "null", "null", "1" };
    assert(kthSmallest(test2.root, 3) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif