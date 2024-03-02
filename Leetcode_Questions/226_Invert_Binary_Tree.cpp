#include <iostream>
#include <assert.h>
#include <vector>
#include <initializer_list>

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


class BST
{
public:
	TreeNode* root;
	std::vector<int> values;

	BST(std::initializer_list<int> values) :
		root(nullptr), values(values)
	{
		this->root = makeTree(this->values);
	}

	~BST()
	{
		deleteTree(this->root);
	}

	bool operator==(BST& tree2)
	{
		return isSameTree(this->root, tree2.root);
	}

	friend std::ostream& operator<<(std::ostream& out, BST& tree)
	{
		out << "[ ";
		for (int value : tree.values)
		{
			out << value << ' ';

		}
		out << ']';
		return out;
	}

	TreeNode* makeTree(std::vector<int>& values)
	{
		if (values.size() - 1 == -1)
			return nullptr;

		return makeNode(values, 0);
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

# if 0
int main()
{
	// Provided test cases
	BST testTree1{ 4, 2, 7, 1, 3, 6, 9 };
	BST answerTree1{ 4, 7, 2, 9, 6, 3, 1 };
	invertTree(testTree1.root);
	assert(testTree1 == answerTree1);

	BST testTree2{ 2, 1, 3 };
	BST answerTree2{ 2, 3, 1 };
	invertTree(testTree2.root);
	assert(testTree2 == answerTree2);

	BST testTree3{};
	BST answerTree3{};
	invertTree(testTree3.root);
	assert(testTree3 == answerTree3);

	std::cout << "Success!\n";

	return 0;
}
#endif