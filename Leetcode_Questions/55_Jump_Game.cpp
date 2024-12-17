#include <iostream>
#include <cassert>
#include <vector>

bool canJump(std::vector<int>& nums)
{
    int remainingJumps{ 0 };
    for (auto& num : nums)
    {
        if (remainingJumps < 0)
            return false;

        if (num > remainingJumps)
            remainingJumps = num;

        --remainingJumps;
    }
    return true;
}

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ 2, 3, 1, 1, 4 };
    assert(canJump(test1) == true);

    std::vector test2{ 3, 2, 1, 0, 4 };
    assert(canJump(test2) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif