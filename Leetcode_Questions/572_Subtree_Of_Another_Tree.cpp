#include <iostream>
#include <assert.h>

#include "Treenode.h"
#include "BinaryTree.h"

bool isSameTree(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    if (root1->val == root2->val)
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);

    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot)
{
    if (!root)
        return false;

    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

#if 0
int main()
{
    // Provided test cases
    BinaryTree tree1{ "3", "4", "5", "1", "2" };
    BinaryTree subtree1{ "4", "1", "2" };
    assert(isSubtree(tree1.root, subtree1.root) == true);

    BinaryTree tree2{ "3", "4", "5", "1", "2", "null", "null", "null", "null", "0" };
    BinaryTree subtree2{ "4", "1", "2" };
    assert(isSubtree(tree2.root, subtree2.root) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif