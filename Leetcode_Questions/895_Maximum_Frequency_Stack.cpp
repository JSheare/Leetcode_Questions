#include <iostream>
#include <cassert>

#include "FreqStack.h"

// See FreqStack.h and FreqStack.cpp for implementation details

#if 0
int main()
{
	// Provided test case
	FreqStack test1;
	test1.push(5);
	test1.push(7);
	test1.push(5);
	test1.push(7);
	test1.push(4);
	test1.push(5);
	assert(test1.pop() == 5);
	assert(test1.pop() == 7);
	assert(test1.pop() == 5);
	assert(test1.pop() == 4);

	std::cout << "Success!\n";

	return 0;
}
#endif