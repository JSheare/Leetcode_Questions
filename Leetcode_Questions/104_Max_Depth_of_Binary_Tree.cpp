#include <iostream>
#include <assert.h>
#include <algorithm>
#include "TreeNode.h"
#include "BinaryTree.h"

int maxDepth(TreeNode* root)
{
    if (!root)
        return 0;

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree test1{ "3", "9", "20", "null", "null", "15", "7" };
    assert(maxDepth(test1.root) == 3);

    BinaryTree test2{ "1", "null", "2" };
    assert(maxDepth(test2.root) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif