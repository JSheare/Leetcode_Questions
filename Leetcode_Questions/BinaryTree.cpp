#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "TreeNode.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree(TreeNode* new_root) :
	root(new_root)
{
	this->values = makeValues(this->root);
}

BinaryTree::BinaryTree(std::initializer_list<std::string> values) :
	root(nullptr), values(values)
{
	this->root = makeTree(this->values);
}

BinaryTree::~BinaryTree()
{
	deleteTree(this->root);
}

TreeNode* BinaryTree::findNode(int val)
{
	return dfs(this->root, val);
}

bool BinaryTree::operator==(BinaryTree& tree2)
{
	return isSameTree(this->root, tree2.root);
}

std::ostream& operator<<(std::ostream& out, BinaryTree& tree)
{
	out << "[ ";
	for (std::string value : tree.values)
	{
		out << value << ' ';
	}
	out << ']';
	return out;
}

TreeNode* BinaryTree::makeTree(std::vector<std::string>& values)
{
	if (values.size() - 1 == -1)
		return nullptr;

	return makeNode(values, 0);
}

TreeNode* BinaryTree::makeNode(std::vector<std::string>& values, int index)
{
	int n{ static_cast<int>(values.size()) };
	if (n <= index || values[index] == "null")
		return nullptr;

	TreeNode* node{ new TreeNode{stoi(values[index])} };
	node->left = makeNode(values, 2 * index + 1);
	node->right = makeNode(values, 2 * index + 2);
	return node;
}

std::vector<std::string> BinaryTree::makeValues(TreeNode* root)
{
	std::queue<TreeNode*> q;
	std::vector<std::string> vals;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* node{ q.front() };
		q.pop();
		if (!node)
			vals.push_back("null");
		else
		{
			vals.push_back(std::to_string(node->val));
			q.push(node->left);
			q.push(node->right);
		}
	}
	return vals;
}

TreeNode* BinaryTree::dfs(TreeNode* root, int val)
{
	if (!root || root->val == val)
		return root;

	TreeNode* left{ dfs(root->left, val) };
	TreeNode* right{ dfs(root->right, val) };
	return left ? left : right;
}

void BinaryTree::deleteTree(TreeNode* root)
{
	if (!root)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

bool BinaryTree::isSameTree(TreeNode* root1, TreeNode* root2)
{
	if (!root1 && !root2)
		return true;
	else if (!root1 || !root2)
		return false;

	return (root1->val == root2->val) &&
		isSameTree(root1->left, root2->left) &&
		isSameTree(root1->right, root2->right);
}