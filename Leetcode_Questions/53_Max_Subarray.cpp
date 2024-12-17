#include <iostream>
#include <cassert>
#include <algorithm>
#include <limits.h>
#include <vector>

int maxSubarray(std::vector<int>& nums)
{
    int currentSum{ 0 };
    int currentMax{ INT_MIN };
    for (int num : nums)
    {
        if (currentSum < 0)
            currentSum = 0;

        currentSum += num;
        currentMax = std::max(currentMax, currentSum);
    }
    return currentMax;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    assert(maxSubarray(test1) == 6);

    std::vector<int> test2{ 1 };
    assert(maxSubarray(test2) == 1);

    std::vector<int> test3{ 5, 4, -1, 7, 8 };
    assert(maxSubarray(test3) == 23);

    std::cout << "Success!\n";

	return 0;
}
#endif