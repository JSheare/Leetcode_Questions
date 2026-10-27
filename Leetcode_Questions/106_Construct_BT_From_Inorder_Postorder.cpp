#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* buildTreeHelper1(std::vector<int>& postorder, std::unordered_map<int, int>& indices, int& pIndex, int start, int end)
{
    if (start > end)
        return nullptr;

    TreeNode* root{ new TreeNode(postorder[pIndex--]) };
    int rootIndex{ indices[root->val] };
    root->right = buildTreeHelper1(postorder, indices, pIndex, rootIndex + 1, end);
    root->left = buildTreeHelper1(postorder, indices, pIndex, start, rootIndex - 1);
    return root;
}

TreeNode* buildTree1(std::vector<int>& inorder, std::vector<int>& postorder)
{
    std::unordered_map<int, int> indices;
    for (int i{ 0 }; i < inorder.size(); ++i)
    {
        indices[inorder[i]] = i;
    }
    int pIndex{ static_cast<int>(postorder.size()) - 1 };
    return buildTreeHelper1(postorder, indices, pIndex, 0, static_cast<int>(inorder.size()) - 1);
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> inorder1{ 9, 3, 15, 20, 7 };
    std::vector<int> postorder1{ 9, 15, 7, 20, 3 };
    BinaryTree result1{ buildTree1(inorder1, postorder1) };
    BinaryTree answer1{ "3", "9", "20", "null", "null", "15", "7" };
    assert(result1 == answer1);

    std::vector<int> inorder2{ -1 };
    std::vector<int> postorder2{ -1 };
    BinaryTree result2{ buildTree1(inorder2, postorder2) };
    BinaryTree answer2{ "-1" };
    assert(result2 == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif