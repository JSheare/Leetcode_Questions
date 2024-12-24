#include <iostream>
#include <cassert>

#include "RandomizedSet.h"

// See RandomizedSet.h and RandomizedSet.cpp for implementation

#if 0
int main()
{
	// Provided test case
	RandomizedSet s;
	assert(s.insert(1) == true);
	assert(s.remove(2) == false);
	assert(s.insert(2) == true);
	int randomNum{ s.getRandom() };
	assert(randomNum == 1 || randomNum == 2);
	assert(s.remove(1) == true);
	assert(s.insert(2) == false);
	assert(s.getRandom() == 2);

	std::cout << "Success!\n";

	return 0;
}
#endif