#include <iostream>
#include <cassert>
#include <vector>

bool rotatedSearchII(std::vector<int>& nums, int target)
{
    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2 };
        if (nums[mid] == target)
            return true;

        // This can happen when rotation happens in the middle of a string of duplicates
        if (nums[low] == nums[mid] && nums[high] == nums[mid])
        {
            ++low;
            --high;
        }
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 2, 5, 6, 0, 0, 1, 2 };
    assert(rotatedSearchII(test1, 0) == true);

    std::vector<int> test2{ 2, 5, 6, 0, 0, 1, 2 };
    assert(rotatedSearchII(test2, 3) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif