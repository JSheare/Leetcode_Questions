#include <iostream>
#include <cassert>
#include <vector>

#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* arrayToTree(std::vector<int>& nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid{ left + (right - left) / 2 };
    TreeNode* node{ new TreeNode(nums[mid]) };
    node->left = arrayToTree(nums, left, mid - 1);
    node->right = arrayToTree(nums, mid + 1, right);
    return node;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums)
{
    return arrayToTree(nums, 0, static_cast<int>(nums.size()) - 1);
}

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ -10, -3, 0, 5, 9 };
    BinaryTree answer1{ sortedArrayToBST(test1) };
    BinaryTree correct1{ "0", "-10", "5", "null", "-3", "null", "9" };
    assert(answer1 == correct1);

    std::vector test2{ 1, 3 };
    BinaryTree answer2{ sortedArrayToBST(test2) };
    BinaryTree correct2{ "1", "null", "3" };
    assert(answer2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif