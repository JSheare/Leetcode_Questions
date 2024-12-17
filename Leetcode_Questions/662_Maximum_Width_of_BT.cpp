#include <iostream>
#include <cassert>
#include <queue>
#include <utility>
#include <algorithm>

#include "TreeNode.h"
#include "BinaryTree.h"

int widthOfBinaryTree(TreeNode* root)
{
    long long maxWidth{ 0 };
    std::queue<std::pair<TreeNode*, long long>> q;
    q.push({ root, 0 });
    while (!q.empty())
    {
        long long levelSize{ static_cast<int>(q.size()) };
        long long first{};
        long long last{};
        for (int i{ 1 }; i <= levelSize; ++i)
        {
            TreeNode* node{ q.front().first };
            long long index{ q.front().second };
            q.pop();
            if (i == 1)
                first = index;
            if (i == levelSize)
                last = index;

            // Calculating indices for child nodes
            // New indices given by binary heap rules:
            // left child index = 2 * index + 1
            // right child index = 2 * index + 2
            if (node->left)
                q.push({ node->left, 2 * index + 1 });

            if (node->right)
                q.push({ node->right, 2 * index + 2 });
        }
        // +1 to account for zero indexing
        maxWidth = std::max(maxWidth, last - first + 1);
    }
    return static_cast<int> (maxWidth);
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "1", "3", "2", "5", "3", "null", "9"};
    assert(widthOfBinaryTree(test1.root) == 4);

    BinaryTree test2{ "1", "3", "2", "5", "null", "null" , "9", "6", "null", "null", "null", "null", "null", "7" };
    assert(widthOfBinaryTree(test2.root) == 7);

    BinaryTree test3{ "1", "3", "2", "5" };
    assert(widthOfBinaryTree(test3.root) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif