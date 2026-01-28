#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// Bottom up dynamic programming solution
#if 0
int jump(std::vector<int>& nums)
{
    std::vector<int> dp(nums.size(), 10001);
    dp[nums.size() - 1] = 0;
    for (int i{ static_cast<int>(nums.size()) - 2 }; i >= 0; --i)
    {
        for (int j{ 1 }; j <= nums[i] && i + j < nums.size(); ++j)
        {
            dp[i] = std::min(dp[i], dp[i + j] + 1);
        }
    }
    return dp[0];
}
#endif

// Greedy BFS-esque solution
#if 1
int jump(std::vector<int>& nums)
{
    int i{ 0 };
    int maxReachable{ 0 };
    int lastJumpedPos{ 0 };
    int jumps{ 0 };
    while (lastJumpedPos < nums.size() - 1)
    {
        maxReachable = std::max(maxReachable, i + nums[i]);
        if (i == lastJumpedPos)
        {
            lastJumpedPos = maxReachable;
            ++jumps;
        }
        ++i;
    }
    return jumps;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 2, 3, 1, 1, 4 };
    assert(jump(test1) == 2);

    std::vector<int> test2{ 2, 3, 0, 1, 4 };
    assert(jump(test2) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif