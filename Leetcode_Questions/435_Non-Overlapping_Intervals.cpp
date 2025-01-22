#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
{
    // Sorting by the end of the interval prioritizes intervals that end earlier
    std::sort(intervals.begin(), intervals.end(), [&](auto& first, auto& second) {return first[1] < second[1]; });
    int keepNum{ 1 };  // The first interval is considered non-overlapping with itself, hence 1
    int left{ 0 };
    for (int right{ 1 }; right < intervals.size(); ++right)
    {
        // Non-overlapping
        if (intervals[left][1] <= intervals[right][0])
        {
            ++keepNum;
            left = right;
        }
    }
    return static_cast<int>(intervals.size()) - keepNum;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 2}, {2, 3}, {3, 4}, {1, 3} };
    assert(eraseOverlapIntervals(test1) == 1);

    std::vector<std::vector<int>> test2{ {1, 2}, {1, 2}, {1, 2} };
    assert(eraseOverlapIntervals(test2) == 2);

    std::vector<std::vector<int>> test3{ {1, 2}, {2, 3} };
    assert(eraseOverlapIntervals(test3) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif