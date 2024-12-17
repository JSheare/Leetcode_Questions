#include <iostream>
#include <cassert>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

int height(TreeNode* root, int& diameter)
{
    if (!root)
        return 0;

    int left{ height(root->left, diameter) };
    int right{ height(root->right, diameter) };
    diameter = std::max(left + right, diameter);
    return 1 + std::max(left, right);
}

int diameterOfBinaryTree(TreeNode* root)
{
    if (!root)
        return 0;

    int diameter{ 0 };
    height(root, diameter);
    return diameter;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "2", "3", "4", "5"};
    assert(diameterOfBinaryTree(test1.root) == 3);

    BinaryTree test2{ "1", "2" };
    assert(diameterOfBinaryTree(test2.root) == 1);

    std::cout << "Success!\n";

	return 0;
}
#endif