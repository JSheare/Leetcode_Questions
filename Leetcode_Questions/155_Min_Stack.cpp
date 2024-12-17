#include <iostream>
#include <cassert>

#include "MinStack.h"

// See MinStack.h for implementation

#if 0
int main()
{
	// Provided test case
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	assert(minStack.getMin() == -3);
	minStack.pop();
	assert(minStack.top() == 0);
	assert(minStack.getMin() == -2);

	std::cout << "Success!\n";

	return 0;
}
#endif