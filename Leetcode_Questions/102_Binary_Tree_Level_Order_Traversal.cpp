#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

#include "TreeNode.h"
#include "BinaryTree.h"

std::vector<std::vector<int>> levelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> answer;
    if (!root)
        return answer;

    std::queue<TreeNode*> q;
    q.push(root);
    int level{ 0 };
    while (!q.empty())
    {
        int size{ static_cast<int>(q.size()) };
        answer.push_back({});
        for (int i{ 0 }; i < size; ++i)
        {
            TreeNode* node{ q.front() };
            q.pop();
            answer[level].push_back(node->val);
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        ++level;
    }
    return answer;
}

# if 0
int main()
{   // Provided test cases
    BinaryTree test1{ "3", "9", "20", "null", "null", "15", "7" };
    std::vector<std::vector<int>> correct1{ {3}, {9, 20}, {15, 7} };
    assert(levelOrder(test1.root) == correct1);

    BinaryTree test2{ "1" };
    std::vector<std::vector<int>> correct2{ {1} };
    assert(levelOrder(test2.root) == correct2);

    BinaryTree test3{};
    std::vector<std::vector<int>> correct3{};
    assert(levelOrder(test3.root) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif