#include <iostream>
#include <assert.h>
#include <vector>

int search(const std::vector<int>& nums, int target)
{
    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2};
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

#if 1
int main()
{
    // Provided test cases
    std::vector<int> test1{ -1, 0, 3, 5, 9, 12 };
    int answer1{ 4 };
    assert(search(test1, 9) == answer1);

    std::vector<int> test2{ -1, 0, 3, 5, 9, 12 };
    int answer2{ -1 };
    assert(search(test2, 2) == answer2);

    std::cout << "Success!\n";

	return 0;
}
#endif