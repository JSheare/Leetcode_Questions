#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

// Regular dynamic programming solution
//int rob(std::vector<int>& nums)
//{
//    if (nums.size() == 1)
//        return nums[0];
//
//    std::vector<int> dp(nums.size(), 0);
//    dp[0] = nums[0];
//    dp[1] = std::max(nums[0], nums[1]);
//    for (int i{ 2 }; i < nums.size(); ++i)
//    {
//        dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);
//    }
//    return dp[nums.size() - 1];
//}

// Space-optimized dynamic programming solution
int rob(std::vector<int>& nums)
{
    if (nums.size() == 1)
        return nums[0];

    int prevPrev{ nums[0] };
    int prev{ std::max(nums[0], nums[1]) };
    int money{ prev };
    for (int i{ 2 }; i < nums.size(); ++i)
    {
        money = std::max(nums[i] + prevPrev, prev);
        prevPrev = prev;
        prev = money;
    }
    return money;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3, 1 };
    assert(rob(test1) == 4);

    std::vector<int> test2{ 2, 7, 9, 3, 1 };
    assert(rob(test2) == 12);

    std::cout << "Success!\n";

    return 0;
}
#endif