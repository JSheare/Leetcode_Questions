#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
    std::vector<std::vector<int>> answer;
    int i{ 0 };
    while (i < intervals.size() && intervals[i][1] < newInterval[0])
    {
        answer.push_back(intervals[i]);
        ++i;
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1])
    {
        newInterval = { std::min(intervals[i][0], newInterval[0]), std::max(intervals[i][1], newInterval[1]) };
        ++i;
    }
    answer.push_back(newInterval);
    while (i < intervals.size()) {
        answer.push_back(intervals[i]);
        ++i;
    }
    return answer;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> intervals1{ {1, 3}, {6, 9} };
    std::vector<int> new1{ 2, 5 };
    std::vector<std::vector<int>> correct1{ {1, 5}, {6, 9} };
    std::vector<std::vector<int>> answer1{ insert(intervals1, new1) };
    assert(answer1 == correct1);

    std::vector<std::vector<int>> intervals2{ {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
    std::vector<int> new2{ 4, 8 };
    std::vector<std::vector<int>> correct2{ {1, 2}, {3, 10}, {12, 16} };
    std::vector<std::vector<int>> answer2{ insert(intervals2, new2) };
    assert(answer2 == correct2);

    std::cout << "Success!\n";

	return 0;
}
#endif