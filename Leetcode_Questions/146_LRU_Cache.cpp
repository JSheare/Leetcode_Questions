#include <iostream>
#include <cassert>

#include "LRUCache.h"

// See CacheNode.h, LRUCache.h, and LRUCache.cpp for implementation

#if 0
int main()
{
	// Provided test cases
	LRUCache test1(2);
	test1.put(1, 1);
	test1.put(2, 2);
	assert(test1.get(1) == 1);
	test1.put(3, 3);
	assert(test1.get(2) == -1);
	test1.put(4, 4);
	assert(test1.get(1) == -1);
	assert(test1.get(3) == 3);

	LRUCache test2(2);
	test2.put(2, 1);
	test2.put(1, 1);
	test2.put(2, 3);
	test2.put(4, 1);
	assert(test2.get(1) == -1);
	assert(test2.get(2) == 3);

	std::cout << "Success!\n";

	return 0;
}
#endif
