#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

int subarraySum(std::vector<int>& nums, int k)
{
    int numSubarrays{ 0 };
    int sum{ 0 };
    std::unordered_map<int, int> sums;
    sums[0] = 1;  // Sum of zero is always present at least once
    for (auto& num : nums)
    {
        sum += num;
        if (sums.contains(sum - k))
            numSubarrays += sums[sum - k];

        ++sums[sum];
    }
    return numSubarrays;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 1, 1 };
    assert(subarraySum(test1, 2) == 2);

    std::vector<int> test2{ 1, 2, 3 };
    assert(subarraySum(test2, 3) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif