#include <iostream>
#include <cassert>

#include "TreeNode.h"
#include "BinaryTree.h"

bool verify(TreeNode* root, long long minVal, long long maxVal)
{
    if (!root)
        return true;

    if (root->val > minVal && root->val < maxVal)
        return verify(root->left, minVal, root->val) && verify(root->right, root->val, maxVal);
    return false;
}

bool isValidBST(TreeNode* root)
{
    return verify(root, -1000000000000, 1000000000000);
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "2", "1", "3"};
    assert(isValidBST(test1.root) == true);

    BinaryTree test2{ "5", "1", "4", "null", "null", "3", "6" };
    assert(isValidBST(test2.root) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif