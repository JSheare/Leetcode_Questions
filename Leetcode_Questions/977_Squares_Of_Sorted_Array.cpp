#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

std::vector<int> sortedSquares(std::vector<int>& nums)
{
    std::vector<int> squares(nums.size(), 0);
    int left{ 0 };
    int right{ static_cast<int>(nums.size()) - 1 };
    for (int i{ right }; i >= 0; --i)
    {
        if (std::abs(nums[left]) > std::abs(nums[right]))
        {
            squares[i] = nums[left] * nums[left];
            ++left;
        }
        else
        {
            squares[i] = nums[right] * nums[right];
            --right;
        }
    }
    return squares;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ -4, -1, 0, 3, 10 };
    std::vector<int> correct1{ 0, 1, 9, 16, 100 };
    assert(sortedSquares(test1) == correct1);

    std::vector<int> test2{ -7, -3, 2, 3, 11 };
    std::vector<int> correct2{ 4, 9, 9, 49, 121 };
    assert(sortedSquares(test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif