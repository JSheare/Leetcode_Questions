#include <iostream>
#include <assert.h>

#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* lowestCommonAncestorBT(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || root == p || root == q)
		return root;

	TreeNode* left{ lowestCommonAncestorBT(root->left, p, q) };
	TreeNode* right{ lowestCommonAncestorBT(root->right, p, q) };
	return left && right ? root : (left ? left : right);
}

# if 0
int main()
{
	// Provided test cases
	BinaryTree test1{ "3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4" };
	assert(lowestCommonAncestorBT(test1.root, test1.findNode(5), test1.findNode(1)) == test1.findNode(3));

	BinaryTree test2{ "3", "5", "1", "6", "2", "0", "8", "null", "null", "7", "4" };
	assert(lowestCommonAncestorBT(test2.root, test2.findNode(5), test2.findNode(4)) == test2.findNode(5));

	BinaryTree test3{ "1", "2" };
	assert(lowestCommonAncestorBT(test3.root, test3.findNode(1), test3.findNode(2)) == test3.findNode(1));

	std::cout << "Success!\n";

	return 0;
}
#endif