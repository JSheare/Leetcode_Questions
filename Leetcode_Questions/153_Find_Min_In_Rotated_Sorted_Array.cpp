#include <iostream>
#include <assert.h>
#include <vector>

int findMin(std::vector<int>& nums)
{
    int left{ 0 };
    int right{ static_cast<int>(nums.size()) - 1 };
    while (left < right)
    {
        int mid{ (right - left) / 2 + left };
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 3, 4, 5, 1, 2 };
    assert(findMin(test1) == 1);

    std::vector<int> test2{ 4, 5, 6, 7, 0, 1, 2 };
    assert(findMin(test2) == 0);

    std::vector<int> test3{ 11, 13, 15, 17 };
    assert(findMin(test3) == 11);

std::cout << "Success!\n";


    return 0;
}
#endif