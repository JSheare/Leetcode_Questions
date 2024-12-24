#include "TrieNode.h"

TrieNode::TrieNode()
{
	for (TrieNode* ptr : child)
	{
		ptr = nullptr;
	}
}

TrieNode::~TrieNode()
{
	for (TrieNode* ptr : child)
	{
		if (ptr)
			delete ptr;
	}
}