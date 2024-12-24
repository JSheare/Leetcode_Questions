#include <iostream>
#include <cassert>
#include <vector>

#include "RandomPickWeighted.h"

// See RandomPickWeighted.h and RandomPickWeighted.cpp for implementation

#if 0
int main()
{
	// Provided test cases
	std::vector test1{ 1 };
	RandomPickWeighted pick1{ test1 };
	int index1{ pick1.pickIndex() };
	assert(index1 == 0);

	std::vector test2{ 1, 3 };
	RandomPickWeighted pick2{ test2 };
	int index2{ pick2.pickIndex() };
	// Index of 1 will be more likely
	assert(index2 == 0 || index2 == 1);

	std::cout << "Success!\n";

	return 0;
}
#endif