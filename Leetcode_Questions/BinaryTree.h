#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

#include "TreeNode.h"

// Not intended to be a super great BT class or anything, but it gets the job done for these questions and their test cases.
class BinaryTree
{
public:
	TreeNode* root;
	std::vector<std::string> values;

	BinaryTree(TreeNode* new_root = nullptr);
	BinaryTree(std::initializer_list<std::string> values);
	~BinaryTree();
	TreeNode* findNode(int val);
	bool operator==(BinaryTree& tree2);
	friend std::ostream& operator<<(std::ostream& out, BinaryTree& tree);

private:
	TreeNode* makeTree(std::vector<std::string>& values);
	TreeNode* makeNode(std::vector<std::string>& values, int index);
	std::vector<std::string> makeValues(TreeNode* root);
	TreeNode* dfs(TreeNode* root, int val);
	void deleteTree(TreeNode* root);
	bool isSameTree(TreeNode* root1, TreeNode* root2);
};
#endif
