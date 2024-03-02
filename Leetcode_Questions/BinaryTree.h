#ifndef BT_H
#define BT_H

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include "TreeNode.h"

// Not intended to be a super great BT class or anything, but it gets the job done for these questions and their test cases.
class BinaryTree
{
public:
	TreeNode* root;
	std::vector<std::string> values;

	BinaryTree(std::initializer_list<std::string> values) :
		root(nullptr), values(values)
	{
		this->root = makeTree(this->values);
	}

	~BinaryTree()
	{
		deleteTree(this->root);
	}

	bool operator==(BinaryTree& tree2)
	{
		return isSameTree(this->root, tree2.root);
	}

	friend std::ostream& operator<<(std::ostream& out, BinaryTree& tree)
	{
		out << "[ ";
		for (std::string value : tree.values)
		{
			out << value << ' ';

		}
		out << ']';
		return out;
	}

private:
	TreeNode* makeTree(std::vector<std::string>& values)
	{
		if (values.size() - 1 == -1)
			return nullptr;

		return makeNode(values, 0);
	}

	TreeNode* makeNode(std::vector<std::string>& values, int index)
	{
		int n{ static_cast<int>(values.size()) };
		if (n <= index || values[index] == "null")
			return nullptr;

		TreeNode* node{ new TreeNode{stoi(values[index])} };
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
#endif
