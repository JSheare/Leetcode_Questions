#include <iostream>
#include <assert.h>
#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if ((p->val >= root->val && q->val <= root->val) ||
		p->val <= root->val && q->val >= root->val)
		return root;
	if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);
	else
		return lowestCommonAncestor(root->right, p, q);
}

#if 0
int main()
{
	// Provided test cases
	BinaryTree tree1{ 6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5 };
	TreeNode p1{ 2 };
	TreeNode q1{ 8 };
	assert(lowestCommonAncestor(tree1.root, &p1, &q1)->val == 6);

	BinaryTree tree2{ 6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5 };
	TreeNode p2{ 2 };
	TreeNode q2{ 4 };
	assert(lowestCommonAncestor(tree2.root, &p2, &q2)->val == 2);

	std::cout << "Success!\n";

	return 0;
}
#endif