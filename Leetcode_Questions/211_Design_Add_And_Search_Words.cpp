#include <iostream>
#include <cassert>
#include <string>

#include "WordDictionary.h"

// See WordDictionary.h and WordDictionary.cpp for implementation

#if 0
int main()
{
	// Provided test case
	WordDictionary wordDict;
	wordDict.addWord("bad");
	wordDict.addWord("dad");
	wordDict.addWord("mad");
	assert(wordDict.search("pad") == false);
	assert(wordDict.search("bad") == true);
	assert(wordDict.search(".ad") == true);
	assert(wordDict.search("b..") == true);

	std::cout << "Success!\n";

	return 0;
}
#endif