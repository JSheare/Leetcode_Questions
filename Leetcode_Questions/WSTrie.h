#ifndef WSTRIE_H
#define WSTRIE_H

class WSTrie
{
public:
    WSTrie* children[26];
    int wordIdx{ -1 };  // Index in words[] array
    int count{ 0 };  // Number of words passing through this node

    WSTrie();
    ~WSTrie();
};
#endif
