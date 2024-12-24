#include <iostream>
#include <cassert>
#include <string>

#include "TimeMap.h"

// See TimeMap.h and TimeMap.cpp for implementation details

#if 0
int main()
{
	// Provided test case
	TimeMap test;
	test.set("foo", "bar", 1);
	assert(test.get("foo", 1) == "bar");
	assert(test.get("foo", 3) == "bar");
	test.set("foo", "bar2", 4);
	assert(test.get("foo", 4) == "bar2");
	assert(test.get("foo", 5) == "bar2");

	std::cout << "Success!\n";

	return 0;
}
#endif