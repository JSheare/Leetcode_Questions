#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    if (intervals.size() == 1)
        return intervals;

    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> newIntervals;
    newIntervals.reserve(intervals.size());
    newIntervals.push_back(intervals[0]);
    for (int i{ 1 }; i < intervals.size(); ++i)
    {
        if (newIntervals.back()[1] < intervals[i][0])
            newIntervals.push_back(intervals[i]);
        else if (newIntervals.back()[1] < intervals[i][1])
            newIntervals.back()[1] = intervals[i][1];
    }
    return newIntervals;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    std::vector<std::vector<int>> correct1{ {1, 6}, {8, 10}, {15, 18} };
    assert(merge(test1) == correct1);

    std::vector<std::vector<int>> test2{ {1, 4}, {4, 5} };
    std::vector<std::vector<int>> correct2{ {1, 5} };
    assert(merge(test2) == correct2);

    std::cout << "Success!\n";
    
    return 0;
}
#endif