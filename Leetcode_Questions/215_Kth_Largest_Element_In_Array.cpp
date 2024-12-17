#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>

// Min-heap solution
#if 1
int findKthLargest(std::vector<int>& nums, int k)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(nums.begin(), nums.begin() + k);
    for (int i{ k }; i < nums.size(); ++i)
    {
        if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
#endif

// Quickselect solution
#if 0
int findKthLargest(std::vector<int>& nums, int k)
{
    int left{ 0 };
    int right{ static_cast<int>(nums.size()) - 1 };
    int storedIndex{ left };
    while (true)
    {
        int pivotIndex{ rand() % (right - left + 1) + left };
        // Partitioning around the pivot
        int pivot{ nums[pivotIndex] };
        std::swap(nums[pivotIndex], nums[right]);
        storedIndex = left;
        for (int i{ left }; i < right; ++i)
        {
            if (nums[i] < pivot)
            {
                std::swap(nums[i], nums[storedIndex]);
                ++storedIndex;
            }
        }
        std::swap(nums[right], nums[storedIndex]);
        // Checking to see if the new pivot index is on the desired value and returning the value if it is
        // Otherwise we do another partitioning iteration
        if (storedIndex == nums.size() - k)
            return nums[storedIndex];
        else if (storedIndex > nums.size() - k)
            right = storedIndex - 1;
        else
            left = storedIndex + 1;

    }
}
#endif

// Standard library partial sorting solution (best performance, but a little lame)
#if 0
int findKthLargest(std::vector<int>& nums, int k)
{
    std::nth_element(nums.begin(), nums.end() - k, nums.end());
    return nums[nums.size() - k];
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 3, 2, 1, 5, 6, 4 };
    assert(findKthLargest(test1, 2) == 5);

    std::vector<int> test2{ 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    assert(findKthLargest(test2, 4) == 4);

    std::cout << "Success!\n";

    return 0;
}
#endif