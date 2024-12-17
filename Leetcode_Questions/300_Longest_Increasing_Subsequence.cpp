#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// Dynamic programming solution  (O(N^2) time complexity)
#if 0
int lengthOfLIS(std::vector<int>& nums)
{
    std::vector<int> dp(nums.size(), 1);
    int maxLen{ 1 };
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        for (int j{ 0 }; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
                maxLen = std::max(maxLen, dp[i]);
            }
        }
    }
    return maxLen;
}
#endif

// Binary search solution  (O(nlog(n) time complexity)
#if 1
int lengthOfLIS(std::vector<int>& nums)
{
    std::vector<int> subseq;
    subseq.push_back(nums[0]);
    for (int i{ 1 }; i < nums.size(); ++i)
    {
        // Finds the location of the next largest num (compared to nums[i]) in the current subsequence
        // via a binary search
        int itr{ static_cast<int>(std::lower_bound(subseq.begin(), subseq.end(), nums[i]) - subseq.begin()) };
        if (itr == subseq.size())  // nums[i] is larger than all nums in the current subsequence, so we just add it
            subseq.push_back(nums[i]);
        else  // Replace the larger value in the current subsequence with the smaller nums[i]
            subseq[itr] = nums[i];
    }
    return static_cast<int>(subseq.size());
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 10, 9, 2, 5, 3, 7, 101, 18 };
    assert(lengthOfLIS(test1) == 4);

    std::vector<int> test2{ 0, 1, 0, 3, 2, 3 };
    assert(lengthOfLIS(test2) == 4);

    std::vector<int> test3{ 7, 7, 7, 7, 7, 7, 7 };
    assert(lengthOfLIS(test3) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif