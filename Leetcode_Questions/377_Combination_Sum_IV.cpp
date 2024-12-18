#include <iostream>
#include <cassert>
#include <vector>

// Dynamic programming solution
#if 1
int combinationSum4(std::vector<int>& nums, int target)
{
    std::vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i{ 1 }; i <= target; ++i)
    {
        for (int j{ 0 }; j < nums.size(); ++j)
        {
            if (i >= nums[j])
                dp[i] += dp[i - nums[j]];
        }
    }
    return static_cast<int>(dp[target]);
}
#endif

// Recursion and memoization solution
#if 0
int solve(std::vector<int>& mem, std::vector<int>& nums, int target)
{
    if (target == 0)
        return 1;

    if (target < 0)
        return 0;

    if (mem[target] != -1)
        return mem[target];

    int ans{ 0 };
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        ans += solve(mem, nums, target - nums[i]);
    }
    mem[target] = ans;
    return mem[target];
}

int combinationSum4(std::vector<int>& nums, int target)
{
    std::vector<int> mem(target + 1, -1);
    return solve(mem, nums, target);
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3 };
    assert(combinationSum4(test1, 4) == 7);

    std::vector<int> test2{ 9 };
    assert(combinationSum4(test2, 3) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif