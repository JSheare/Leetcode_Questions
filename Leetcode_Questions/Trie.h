#ifndef TRIE_H
#define TRIE_H

#include <string>

#include "TrieNode.h"

class Trie
{
public:
	TrieNode* root;

	Trie() :
		root{ new TrieNode() }
	{}
	~Trie()
	{
		delete root;
	}
	void insert(std::string s)
	{
		TrieNode* node{ root };
		for (char& c : s)
		{
			int i{ c - 'a' };
			if (!node->child[i])
				node->child[i] = new TrieNode();

			node = node->child[i];
		}
		node->isWord = true;
	}
	bool search(std::string key, bool prefix = false)
	{
		TrieNode* node{ root };
		for (char& c : key)
		{
			int i{ c - 'a' };
			if (!node->child[i])
				return false;

			node = node->child[i];
		}
		if (!prefix)
			return node->isWord;

		return true;
	}
	bool startsWith(std::string prefix)
	{
		return search(prefix, true);
	}
};
#endif
