#include <iostream>
#include <assert.h>
#include "TreeNode.h"
#include "BinaryTree.h"

TreeNode* invertTree(TreeNode* root)
{
	if (!root)
	{
		return nullptr;
	}

	TreeNode* temp{ root->right };
	root->right = invertTree(root->left);
	root->left = invertTree(temp);

	return root;
}

# if 0
int main()
{
	// Provided test cases
	BinaryTree testTree1{ "4", "2", "7", "1", "3", "6", "9" };
	BinaryTree answerTree1{ "4", "7", "2", "9", "6", "3", "1" };
	invertTree(testTree1.root);
	assert(testTree1 == answerTree1);

	BinaryTree testTree2{ "2", "1", "3" };
	BinaryTree answerTree2{ "2", "3", "1" };
	invertTree(testTree2.root);
	assert(testTree2 == answerTree2);

	BinaryTree testTree3{};
	BinaryTree answerTree3{};
	invertTree(testTree3.root);
	assert(testTree3 == answerTree3);

	std::cout << "Success!\n";

	return 0;
}
#endif