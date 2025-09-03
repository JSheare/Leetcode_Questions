#include <string>

#include "Trie.h"
#include "TrieNode.h"

Trie::Trie() :
	root{ new TrieNode() }
{}

Trie::~Trie()
{
	delete root;
}

void Trie::insert(std::string s)
{
	TrieNode* node{ root };
	for (char& c : s)
	{
		int i{ c - 'a' };
		if (!node->children[i])
			node->children[i] = new TrieNode();

		node = node->children[i];
	}
	node->isWord = true;
}

bool Trie::search(std::string key, bool prefix)
{
	TrieNode* node{ root };
	for (char& c : key)
	{
		int i{ c - 'a' };
		if (!node->children[i])
			return false;

		node = node->children[i];
	}
	if (!prefix)
		return node->isWord;

	return true;
}

bool Trie::startsWith(std::string prefix)
{
	return search(prefix, true);
}