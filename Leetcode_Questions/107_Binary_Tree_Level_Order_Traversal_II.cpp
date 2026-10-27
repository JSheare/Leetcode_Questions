#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
{
    if (!root)
        return {};

    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<std::vector<int>> levels;
    while (!q.empty())
    {
        int levelSize{ static_cast<int>(q.size()) };
        std::vector<int> level;
        level.reserve(levelSize);
        while (levelSize)
        {
            TreeNode* curr{ q.front() };
            q.pop();
            level.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);

            --levelSize;
        }
        levels.push_back(level);
    }
    reverse(levels.begin(), levels.end());
    return levels;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree input1{ "3", "9", "20", "null", "null", "15", "7" };
    std::vector<std::vector<int>> answer1{ {15, 7}, {9, 20}, {3} };
    std::vector<std::vector<int>> result1{ levelOrderBottom(input1.root) };
    assert(result1 == answer1);

    BinaryTree input2{ "1" };
    std::vector<std::vector<int>> answer2{ {1} };
    std::vector<std::vector<int>> result2{ levelOrderBottom(input2.root) };
    assert(result2 == answer2);

    BinaryTree input3;
    std::vector<std::vector<int>> answer3;
    std::vector<std::vector<int>> result3{ levelOrderBottom(input3.root) };
    assert(result3 == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif