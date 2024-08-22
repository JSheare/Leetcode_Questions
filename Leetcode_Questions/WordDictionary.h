#ifndef WORDDICTIONARY_H
#define WORDDICTIONARY_H

#include <string>

#include "TrieNode.h"

// Essentially just a modified trie
class WordDictionary
{
public:
    TrieNode* root;

    WordDictionary() :
        root{ new TrieNode }
    {}
    ~WordDictionary()
    {
        delete root;
    }
    void addWord(std::string word)
    {
        TrieNode* node{ root };
        for (char& c : word)
        {
            int i{ c - 'a' };
            if (!node->child[i])
                node->child[i] = new TrieNode();

            node = node->child[i];
        }
        node->isWord = true;
    }
    bool search(std::string word)
    {
        return searchNode(word, root, 0);
    }
private:
    bool searchNode(std::string& word, TrieNode* node, int index)
    {
        if (!node)
            return false;

        if (index == word.size())
            return node->isWord;

        if (word[index] != '.')  // Dot is a wildcard character
            return searchNode(word, node->child[word[index] - 'a'], index + 1);

        for (int i{ 0 }; i < 26; ++i)
        {
            if (node->child[i])
            {
                if (searchNode(word, node->child[i], index + 1))
                    return true;
            }
        }
        return false;
    }
};

#endif
