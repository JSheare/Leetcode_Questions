#include <iostream>
#include <assert.h>
#include <vector>
#include <unordered_map>
#include <algorithm>


int findMaxLength(std::vector<int>& nums)
{
    std::unordered_map<int, int> mp;
    mp[0] = -1;
    int prefixSum{ 0 };
    int maxLen{ 0 };
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        prefixSum += (nums[i] == 1) ? 1 : -1;
        if (mp.contains(prefixSum))
        {
            maxLen = std::max(maxLen, i - mp[prefixSum]);
        }
        else
            mp[prefixSum] = i;
    }
    return maxLen;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 0, 1 };
    assert(findMaxLength(test1) == 2);

    std::vector<int> test2{ 0, 1, 0 };
    assert(findMaxLength(test2) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif