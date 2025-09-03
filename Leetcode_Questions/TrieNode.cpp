#include "TrieNode.h"

TrieNode::TrieNode()
{
	for (int i{0}; i < 26; ++i)
	{
		children[i] = nullptr;
	}
}

TrieNode::~TrieNode()
{
	for (TrieNode* ptr : children)
	{
		delete ptr;
	}
}