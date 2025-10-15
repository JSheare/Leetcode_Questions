#include <iostream>
#include <cassert>
#include <vector>

int firstMissingPositive(std::vector<int>& nums)
{
    // For an array of length n, the smallest positive integer not in the array is either on the range [1, n]
    // or, if the array already contains numbers 1-n, n + 1
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        // Removing all negative numbers to prevent them from being checked later
        if (nums[i] < 0)
            nums[i] = 0;
    }
    // Checking for missing numbers on the range [1, n]
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        int val{ abs(nums[i]) };
        if (val > 0 && val <= nums.size())
        {
            // Marking the bucket for this number (val)
            // A bucket space that's already occupied could be a valid number down the line, so we just flip its sign
            // A bucket space that's unoccupied (0) isn't a valid number, so we mark it with -(n + 1), which is out of range
            if (nums[val - 1] > 0)
                nums[val - 1] *= -1;
            else if (nums[val - 1] == 0)
                nums[val - 1] = -1 * (static_cast<int>(nums.size()) + 1);
        }
    }
    for (int i{ 1 }; i <= nums.size(); ++i)
    {
        if (nums[i - 1] >= 0)
            return i;
    }
    return static_cast<int>(nums.size()) + 1;  // Only happens if all numbers 1-n are present in the array
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> nums1{ 1, 2, 0 };
    assert(firstMissingPositive(nums1) == 3);

    std::vector<int> nums2{ 3, 4, -1, 1 };
    assert(firstMissingPositive(nums2) == 2);

    std::vector<int> nums3{ 7, 8, 9, 11, 12 };
    assert(firstMissingPositive(nums3) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif