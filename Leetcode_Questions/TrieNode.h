#ifndef TRIENODE_H
#define TRIENODE_H

class TrieNode
{
public:
	TrieNode* child[26]{};
	bool isWord{ false };

	TrieNode()
	{
		for (TrieNode* ptr : child)
		{
			ptr = nullptr;
		}
	}
	~TrieNode()
	{
		for (TrieNode* ptr: child)
		{
			if (ptr)
				delete ptr;
		}
	}
};
#endif
