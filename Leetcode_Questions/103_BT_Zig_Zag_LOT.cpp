#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
{
    if (!root)
        return {};

    std::vector<std::vector<int>> levels;
    std::queue<TreeNode*> q;
    q.push(root);
    bool zig{ false };
    while (!q.empty())
    {
        std::vector<int> level;
        for (int i{ static_cast<int>(q.size()) }; i > 0; --i)
        {
            TreeNode* node{ q.front() };
            q.pop();
            level.push_back(node->val);
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        if (zig)
            std::reverse(level.begin(), level.end());

        levels.push_back(level);
        zig = !zig;
    }
    return levels;
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "9", "20", "null", "null", "15", "7" };
    std::vector<std::vector<int>> correct1{ {3}, {20, 9}, {15, 7} };
    assert(zigzagLevelOrder(test1.root) == correct1);

    BinaryTree test2{ "1" };
    std::vector<std::vector<int>> correct2{ {1} };
    assert(zigzagLevelOrder(test2.root) == correct2);

    BinaryTree test3{};
    std::vector<std::vector<int>> correct3{};
    assert(zigzagLevelOrder(test3.root) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif