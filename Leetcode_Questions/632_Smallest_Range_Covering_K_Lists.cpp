#include <iostream>
#include <cassert>
#include <vector>
#include <limits.h>
#include <utility>
#include <algorithm>
#include <queue>

std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
{
    auto comp{ [&](std::pair<int, int>& a, std::pair<int, int>& b) {
        return nums[a.first][a.second] > nums[b.first][b.second]; } };
    int minimum{ INT_MAX };
    int maximum{ INT_MIN };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        minimum = std::min(minimum, nums[i][0]);
        maximum = std::max(maximum, nums[i][0]);
        pq.push({ i, 0 });
    }
    std::vector<int> range{ minimum, maximum };
    while (!pq.empty())
    {
        std::pair<int, int> curr{ pq.top() };
        pq.pop();
        minimum = nums[curr.first][curr.second];
        if (maximum - minimum < range[1] - range[0])
        {
            range[0] = minimum;
            range[1] = maximum;
        }
        if (curr.second + 1 < nums[curr.first].size())
        {
            maximum = std::max(maximum, nums[curr.first][curr.second + 1]);
            pq.push({ curr.first, curr.second + 1 });
        }
        else
            break;  // One of the lists has been exhausted
    }
    return range;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30} };
    assert(smallestRange(test1) == std::vector<int>({20, 24}));

    std::vector<std::vector<int>> test2{ {1, 2, 3}, {1, 2, 3}, {1, 2, 3} };
    assert(smallestRange(test2) == std::vector<int>({ 1, 1 }));

    std::cout << "Success!\n";

    return 0;
}
#endif