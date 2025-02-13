#include <iostream>
#include <cassert>
#include <cstdlib>

#include "MedianFinder.h"

// See MedianFinder.h and MedianFinder.cpp for implementation details

#if 0
int main()
{
	// Provided test case
	double thresh1{ 10e-5 };
	MedianFinder test1;
	test1.addNum(1);
	test1.addNum(2);
	assert(std::abs(test1.findMedian() - 1.5) <= thresh1);
	test1.addNum(3);
	assert(std::abs(test1.findMedian() - 2.0) <= thresh1);

	std::cout << "Success!\n";
	
	return 0;
}
#endif