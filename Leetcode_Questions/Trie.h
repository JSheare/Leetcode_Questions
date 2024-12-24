#ifndef TRIE_H
#define TRIE_H

#include <string>

#include "TrieNode.h"

class Trie
{
public:
	TrieNode* root;

	Trie();
	~Trie();
	void insert(std::string s);
	bool search(std::string key, bool prefix = false);
	bool startsWith(std::string prefix);
};
#endif
