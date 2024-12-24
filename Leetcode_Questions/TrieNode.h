#ifndef TRIENODE_H
#define TRIENODE_H

class TrieNode
{
public:
	TrieNode* child[26]{};
	bool isWord{ false };

	TrieNode();
	~TrieNode();
};
#endif
