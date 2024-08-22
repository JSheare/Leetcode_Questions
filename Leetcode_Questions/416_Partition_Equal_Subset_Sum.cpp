#include <iostream>
#include <assert.h>
#include <vector>

// Full partition table solution (not as time efficient)
#if 0
bool isSubsetSum(std::vector<int>& nums, int sum)
{
    std::vector<std::vector<bool>> part_table(nums.size() + 1, std::vector<bool>(sum + 1, false));
    for (int i{ 0 }; i <= nums.size(); ++i)
    {
        // zero sum will always be possible
        part_table[i][0] = true;
    }

    // Filling out the partition table from the bottom up
    for (int i{ 1 }; i <= nums.size(); ++i)
    {
        for (int j{ 1 }; j <= sum; ++j)
        {
            if (nums[i - 1] <= j)  // If the current number is less than the current sum
                // Check if adding the current element gets us to the current sum
                part_table[i][j] = (part_table[i - 1][j - nums[i - 1]]) || part_table[i - 1][j];
            else  // Otherwise just check if current sum was possible with one fewer element
                part_table[i][j] = part_table[i - 1][j];
        }
    }
    return part_table[nums.size()][sum];
}
#endif

# if 1
bool isSubsetSum(std::vector<int>& nums, int sum)
{
    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1;  // A sum of 0 will always be possible
    // for each number
    for (auto& num : nums)
    {
        // for each possible sum >= num
        for (int i{ sum }; i >= num; --i)
        {
            // check if current sum is possible with current number (or another already found)
            dp[i] = dp[i] ? dp[i] : dp[i - num];
        }
    }
    return dp[sum];
}
#endif

bool canPartition(std::vector<int>& nums)
{
    int sum{ 0 };
    for (auto& num: nums)
    {
        sum += num;
    }
    if (sum % 2 != 0)
        return false;
    else  // Only possible if the sum of the whole array is even
        return isSubsetSum(nums, sum / 2);
}

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ 1, 5, 11, 5 };
    assert(canPartition(test1) == true);

    std::vector test2{ 1, 2, 3, 5 };
    assert(canPartition(test2) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif