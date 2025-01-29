#include <iostream>
#include <cassert>

#include "TreeNode.h"
#include "BinaryTree.h"

// This function is identical to the one defined in BinaryTree.cpp
bool sameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q)
        return true;
    else if (!p || !q)
        return false;

    return (p->val == q->val) &&
        sameTree(p->left, q->left) &&
        sameTree(p->right, q->right);
}

#if 1
int main()
{
    // Provided test cases
    BinaryTree test1P{ "1", "2", "3" };
    BinaryTree test1Q{ "1", "2", "3" };
    assert(sameTree(test1P.root, test1Q.root));

    BinaryTree test2P{ "1", "2" };
    BinaryTree test2Q{ "1", "null", "2" };
    assert(sameTree(test2P.root, test2Q.root) == false);

    BinaryTree test3P{ "1", "2", "1" };
    BinaryTree test3Q{ "1", "1", "2" };
    assert(sameTree(test3P.root, test3Q.root) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif