#include <iostream>
#include <cassert>
#include <vector>

// Binary search solution
#if 0
int findDuplicate(std::vector<int>& nums)
{
    int low{ 1 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (low < high)
    {
        int mid{ low + (high - low) / 2 };
        int count{ 0 };
        for (int num : nums)
        {
            if (num <= mid)
                ++count;
        }
        if (count > mid)
            high = mid;

        else
            low = mid + 1;
    }
    return low;
}
#endif

// Two pointers cycle solution
#if 1
int findDuplicate(std::vector<int>& nums)
{
    int slow{ nums[0] };
    int fast{ nums[0] };
    // Finding the intersection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Finding the cycle entrance
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 3, 4, 2, 2 };
    assert(findDuplicate(test1) == 2);

    std::vector<int> test2{ 3, 1, 3, 4, 2 };
    assert(findDuplicate(test2) == 3);

    std::vector<int> test3{ 3, 3, 3, 3, 3 };
    assert(findDuplicate(test2) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif