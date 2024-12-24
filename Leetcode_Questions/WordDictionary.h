#ifndef WORDDICTIONARY_H
#define WORDDICTIONARY_H

#include <string>

#include "TrieNode.h"

// Essentially just a modified trie
class WordDictionary
{
public:
    TrieNode* root;

    WordDictionary();
    ~WordDictionary();
    void addWord(std::string word);
    bool search(std::string word);

private:
    bool searchNode(std::string& word, TrieNode* node, int index);
};

#endif
