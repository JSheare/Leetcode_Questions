#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_set>
#include <algorithm>

// Despite asking for a solution that runs in O(n) time, leetcode still accepts this one (which is O(nlogn) due to the sort)
// Here for completeness, but it's not a proper solution
#if 0
int longestConsecutive(std::vector<int>& nums)
{
    if (!nums.size())
        return 0;

    std::sort(nums.begin(), nums.end());
    int prev{ INT_MIN };
    int currLen{ 0 };
    int longest{ 0 };
    for (int num : nums)
    {
        if (num - 1 == prev)
        {
            ++currLen;
            prev = num;
        }
        else if (prev != num)
        {
            currLen = 1;
            prev = num;
        }
        longest = std::max(longest, currLen);
    }
    return longest;
}
#endif

// Proper O(n) solution. Nested loops make it look like O(n^2) at first glance, but the while loop will never visit more than n elements across the whole
// algorithm, so it's O(n + n) = O(n)
#if 1
int longestConsecutive(std::vector<int>& nums)
{
    int longest{ 0 };
    int currNum{ 0 };
    int currLen{ 0 };
    std::unordered_set<int> set(nums.begin(), nums.end());
    for (int num : nums)
    {
        if (!set.count(num - 1))
        {
            currNum = num;
            currLen = 1;
            while (set.count(currNum + 1))
            {
                ++currNum;
                ++currLen;
            }
            longest = std::max(longest, currLen);
        }
    }
    return longest;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 100, 4, 200, 1, 3, 2 };
    assert(longestConsecutive(test1) == 4);

    std::vector<int> test2{ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
    assert(longestConsecutive(test2) == 9);

    std::cout << "Success!\n";

    return 0;
}
#endif