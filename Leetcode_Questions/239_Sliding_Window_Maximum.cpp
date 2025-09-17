#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <algorithm>

// Monotonic queue solution
#if 0
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
    std::vector<int> maxes;
    std::deque<int> mq;  // Using this as a backing data structure for the monotonic queue
    for (int i = 0; i < nums.size(); i++)
    {
        // Popping the element at the left end of the window before sliding (if it survived this long)
        if (!mq.empty() && mq.front() <= i - k)
            mq.pop_front();

        // Pushing the new element onto the monotonic queue, which requires popping from the back
        // until decreasing monotonicity is restored
        while (!mq.empty() && nums[mq.back()] <= nums[i])
            mq.pop_back();

        mq.push_back(i);

        // Recording the current window maximum
        if (i >= k - 1)
            maxes.push_back(nums[mq.front()]);
    }
    return maxes;
}
#endif

// Dynamic programming solution (faster but (I think) less elegant, and less space-efficient)
#if 1
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
{
    // Recording the accumulative maximum for k-sized blocks of the array, doing passes starting from both the left and the right
    // Doing left AND right passes is necessary because of the lack of advance information in each pass on its own
    // A maximum recorded at left[i] can, at best, only come from the previous i - k numbers (or i + k in the right pass case)
    // So, by comparing the maximums from both passes, we get the real maximum for the current window
    std::vector<int> left(nums.size());
    std::vector<int> right(nums.size());
    std::vector<int> maxes;
    maxes.reserve(nums.size() - k + 1);
    // Left pass. Final maximum stored at the end of the block
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        left[i] = i % k == 0 ? nums[i] : std::max(left[i - 1], nums[i]);
    }
    // Right pass. Final maximum stored at the beginning of the block
    for (int i{ static_cast<int>(nums.size()) - 1 }; i >= 0; --i)
    {
        right[i] = ((i + 1) % k == 0 || i == nums.size() - 1) ? nums[i] : std::max(right[i + 1], nums[i]);
    }
    // Pass comparison and maximum recording
    for (int i{ 0 }; i + k <= nums.size(); ++i)
    {
        maxes.push_back(std::max(right[i], left[i + k - 1]));
    }
    return maxes;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 3, -1, -3, 5, 3, 6, 7 };
    std::vector<int> answer1{ 3, 3, 5, 5, 6, 7 };
    assert(maxSlidingWindow(test1, 3) == answer1);

    std::vector<int> test2{ 1 };
    std::vector<int> answer2{ 1 };
    assert(maxSlidingWindow(test2, 1) == answer2);

    std::cout << "Success!\n";

    return 0;
}

#endif