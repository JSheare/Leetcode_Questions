#include <iostream>
#include <assert.h>
#include <vector>

// Operates on the principle that A XOR B XOR A = B, order is not important
int singleNumber(std::vector<int>& nums)
{
    int single{ nums[0] };
    for (int i{ 1 }; i < nums.size(); ++i)
    {
        single ^= nums[i];
    }
    return single;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 2, 2, 1 };
    assert(singleNumber(test1) == 1);

    std::vector<int> test2{ 4, 1, 2, 1, 2 };
    assert(singleNumber(test2) == 4);

    std::vector<int> test3{ 1 };
    assert(singleNumber(test3) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif