#ifndef MEDIANFINDER_H
#define MEDIANFINDER_H

#include <queue>
#include <vector>
#include <functional>

class MedianFinder
{
public:
	void addNum(int num);
	double findMedian();

private:
	// Dividing the data into two halves maintained by two heaps, which keeps the middle constantly exposed
	std::priority_queue<int, std::vector<int>, std::less<int>> leftHalf;  // Max heap
	std::priority_queue<int, std::vector<int>, std::greater<int>> rightHalf;  // Min heap

	void balance();
};
#endif