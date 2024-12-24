#include <iostream>
#include <cassert>
#include <string>

#include "Trie.h"

// See Trie.h and Trie.cpp for implementation

#if 0
int main()
{
	// Provided test cases
	Trie test1;
	test1.insert("apple");
	assert(test1.search("apple"));
	assert(!test1.search("app"));
	assert(test1.startsWith("app"));
	test1.insert("app");
	assert(test1.search("app"));

	std::cout << "Success!\n";

	return 0;
}
#endif
