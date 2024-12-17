#include <iostream>
#include <cassert>
#include <vector>


int search(std::vector<int>& nums, int target)
{
    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2 };
        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])  // left half is sorted
        {
            if (nums[low] <= target && target < nums[mid])  // target lies in this half
                high = mid - 1;
            else  // target in the other half
                low = mid + 1;
        }
        else  // right half is sorted
        {
            if (nums[mid] < target && target <= nums[high]) // target lies in this half
                low = mid + 1;
            else  // target in the other half
                high = mid - 1;
        }
    }
    return -1;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 4, 5, 6, 7, 0, 1, 2 };
    assert(search(test1, 0) == 4);

    std::vector<int> test2{ test1 };
    assert(search(test2, 3) == -1);

    std::vector<int> test3{ 1 };
    assert(search(test3, 0) == -1);

    std::cout << "Success!\n";

    return 0;
}
#endif