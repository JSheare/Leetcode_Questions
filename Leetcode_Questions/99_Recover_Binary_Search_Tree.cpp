#include <iostream>
#include <cassert>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end)
{
    // Inorder traversal
    if (!root)
        return;

    markTree(root->left, prev, first, end);
    if (prev)
    {
        // If there's a discontinuity
        if (root->val < prev->val)
        {
            // Marking the first discontinuity
            if (!first)
                first = prev;

            end = root;
        }
    }
    prev = root;
    markTree(root->right, prev, first, end);
}

void recoverTree(TreeNode* root)
{
    TreeNode* prev{ nullptr };
    TreeNode* first{ nullptr };
    TreeNode* end{ nullptr };
    markTree(root, prev, first, end);
    std::swap(first->val, end->val);
    return;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree input1{ "1", "3", "null", "null", "2" };
    BinaryTree correct1{ "3", "1", "null", "null", "2" };
    recoverTree(input1.root);
    assert(input1 == correct1);

    BinaryTree input2{ "3", "1", "4", "null", "null", "2" };
    BinaryTree correct2{ "2", "1", "4", "null", "null", "3" };
    recoverTree(input2.root);
    assert(input2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif