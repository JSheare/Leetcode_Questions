#include <iostream>
#include <assert.h>
#include <vector>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() :
		val(0), left(nullptr), right(nullptr)
	{}

	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr)
	{}

	TreeNode(int x, TreeNode* left, TreeNode* right) :
		val(x), left(left), right(right)
	{}
};

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

TreeNode* makeNode(std::vector<int>& values, int index)
{
	int n{ static_cast<int>(values.size()) };
	if (n <= index)
		return nullptr;

	TreeNode* node{ new TreeNode{values[index]} };
	node->left = makeNode(values, 2 * index + 1);
	node->right = makeNode(values, 2 * index + 2);
	return node;
}

TreeNode* makeTree(std::vector<int>& values)
{
	if (values.size() - 1 == -1)
		return nullptr;

	return makeNode(values, 0);
}

void deleteTree(TreeNode* root)
{
	if (!root)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

bool isSameTree(TreeNode* root1, TreeNode* root2)
{
	if (!root1 && !root2)
		return true;
	else if (!root1 || !root2)
		return false;

	return (root1->val == root2->val) && 
		isSameTree(root1->left, root2->left) && 
		isSameTree(root1->right, root2->right);
}

# if 0
int main()
{
	TreeNode* testTree;
	TreeNode* correctAnswerTree;
	TreeNode* answerTree;

	// Provided test cases
	std::vector<int> test1{ 4, 2, 7, 1, 3, 6, 9 };
	std::vector<int> answer1{ 4, 7, 2, 9, 6, 3, 1 };
	testTree = makeTree(test1);
	correctAnswerTree = makeTree(answer1);
	answerTree = invertTree(testTree);
	assert(isSameTree(answerTree, answerTree));
	deleteTree(correctAnswerTree);
	deleteTree(answerTree);

	std::vector<int> test2{ 2, 1, 3 };
	std::vector<int> answer2{ 2, 3, 1 };
	testTree = makeTree(test2);
	correctAnswerTree = makeTree(answer2);
	answerTree = invertTree(testTree);
	assert(isSameTree(answerTree, answerTree));
	deleteTree(correctAnswerTree);
	deleteTree(answerTree);

	std::vector<int> test3{};
	std::vector<int> answer3{};
	testTree = makeTree(test3);
	correctAnswerTree = makeTree(answer3);
	answerTree = invertTree(testTree);
	assert(isSameTree(answerTree, answerTree));
	deleteTree(correctAnswerTree);
	deleteTree(answerTree);


	std::cout << "Success!\n";

	return 0;
}
#endif