#include <iostream>
#include <assert.h>
#include <vector>
#include <utility>
#include <algorithm>

int maxProduct(std::vector<int>& nums)
{
    int absMax{ nums[0] };
    int iMax{ nums[0] };
    int iMin{ nums[0] };
    for (int i{ 1 }; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
            std::swap(iMax, iMin);

        iMax = std::max(nums[i], iMax * nums[i]);
        iMin = std::min(nums[i], iMin * nums[i]);
        absMax = std::max(absMax, iMax);
    }
    return absMax;
}


// Note: leetcode devs added (probably recently) a testcase that results in overflow errors, so you'd actually need to use doubles 
// instead of ints to pass with this. But, putting that sloppyness aside, this IS the correct answer according to the stated constraints. 

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 2, 3, -2, 4 };
    assert(maxProduct(test1) == 6);

    std::vector<int> test2{ -2, 0, -1 };
    assert(maxProduct(test2) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif