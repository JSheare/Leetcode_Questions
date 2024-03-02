#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include "TreeNode.h"
#include "BinaryTree.h"

int height(TreeNode* root)
{
    if (!root)
        return 0;

    int leftHeight{ height(root->left) };
    if (leftHeight == -1)
        return -1;

    int rightHeight{ height(root->right) };
    if (rightHeight == -1)
        return -1;

    if (abs(rightHeight - leftHeight) > 1)
        return -1;

    return 1 + std::max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root)
{
    return height(root) != -1;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "9", "20", "null", "null", "15", "7"};
    assert(isBalanced(test1.root) == true);

    BinaryTree test2{ "1", "2", "2", "3", "3", "null", "null", "4", "4"};
    assert(isBalanced(test2.root) == false);

    BinaryTree test3{};
    assert(isBalanced(test3.root) == true);

    std::cout << "Success!\n";

	return 0;
}
#endif