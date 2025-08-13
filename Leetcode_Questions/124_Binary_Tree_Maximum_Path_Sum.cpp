#include <iostream>
#include <cassert>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

int maxPathSumHelper(TreeNode* node, int& currMax)
{
    if (!node)
        return 0;

    int leftSum{ std::max(0, maxPathSumHelper(node->left, currMax)) };
    int rightSum{ std::max(0, maxPathSumHelper(node->right, currMax)) };

    // Checking the path that splits at this node
    currMax = std::max(currMax, leftSum + node->val + rightSum);

    // Returning the maximum path that includes this node
    return std::max(leftSum, rightSum) + node->val;
}


int maxPathSum(TreeNode* root)
{
    int currMax{ root->val };
    maxPathSumHelper(root, currMax);
    return currMax;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "2", "3"};
    assert(maxPathSum(test1.root) == 6);

    BinaryTree test2{ "-10", "9", "20", "null", "null", "15", "7" };
    assert(maxPathSum(test2.root) == 42);

    std::cout << "Success!\n";

    return 0;
}
#endif