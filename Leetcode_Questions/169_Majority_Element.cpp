#include <iostream>
#include <cassert>
#include <vector>

// This is the Boyer-Moore majority vote algorithm
int majorityElement(std::vector<int>& nums)
{
    int count{ 0 };
    int candidate{ 0 };
    for (int num : nums)
    {
        if (!count)
            candidate = num;

        if (num == candidate)
            ++count;
        else
            --count;
    }
    return candidate;
}

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ 3, 2, 3 };
    assert(majorityElement(test1) == 3);

    std::vector test2{ 2, 2, 1, 1, 1, 2, 2 };
    assert(majorityElement(test2) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif