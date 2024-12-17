#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* buildSubtree(std::vector<int>& preorder, std::unordered_map<int, int>& map, int& index, int start, int end)
{
    if (end < start)
        return nullptr;

    TreeNode* root{ new TreeNode(preorder[index]) };
    ++index;
    root->left = buildSubtree(preorder, map, index, start, map[root->val] - 1);
    root->right = buildSubtree(preorder, map, index, map[root->val] + 1, end);
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    std::unordered_map<int, int> map;
    for (int i{ 0 }; i < inorder.size(); ++i)
    {
        map[inorder[i]] = i;
    }
    int index{ 0 };
    return buildSubtree(preorder, map, index, 0, static_cast<int>(inorder.size()) - 1);
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> preorder1{ 3, 9, 20, 15, 7 };
    std::vector<int> inorder1{ 9, 3, 15, 20, 7 };
    BinaryTree correct1{ "3", "9", "20", "null", "null", "15", "7" };
    BinaryTree answer1{ buildTree(preorder1, inorder1) };
    assert(answer1 == correct1);

    std::vector<int> preorder2{ -1 };
    std::vector<int> inorder2{ -1 };
    BinaryTree correct2{ "-1" };
    BinaryTree answer2{ buildTree(preorder2, inorder2) };
    assert(answer2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif