#include <iostream>
#include <cassert>

#include "TreeNode.h"
#include "BinaryTree.h"

bool hasPathSum(TreeNode* root, int targetSum)
{
    if (!root)
        return false;

    if (!root->left && !root->right)
        return targetSum - root->val == 0;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "null", "1" };
    assert(hasPathSum(test1.root, 22) == true);

    BinaryTree test2{ "1", "2", "3" };
    assert(hasPathSum(test2.root, 5) == false);

    BinaryTree test3;
    assert(hasPathSum(test3.root, 0) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif