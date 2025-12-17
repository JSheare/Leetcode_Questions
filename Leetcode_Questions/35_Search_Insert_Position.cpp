#include <iostream>
#include <cassert>
#include <vector>

int searchInsert(std::vector<int>& nums, int target)
{
    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2 };
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;  // Same as binary search except for this line
}

#if 0
int main()
{
    // Provided test cases

    std::vector<int> test1{ 1, 3, 5, 6 };
    assert(searchInsert(test1, 5) == 2);

    std::vector<int> test2{ 1, 3, 5, 6 };
    assert(searchInsert(test2, 2) == 1);

    std::vector<int> test3{ 1, 3, 5, 6 };
    assert(searchInsert(test3, 7) == 4);

    std::cout << "Success!\n";

    return 0;
}
#endif