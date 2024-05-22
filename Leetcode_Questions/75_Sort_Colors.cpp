#include <iostream>
#include <assert.h>
#include <vector>
#include <utility>

// This is just the Dutch national flag algorithm
void sortColors(std::vector<int>& nums)
{
    int low{ 0 };
    int mid{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    while (mid <= high)
    {
        if (nums[mid] < 1)
        {
            std::swap(nums[low], nums[mid]);
            ++low;
            ++mid;
        }
        else if (nums[mid] > 1)
        {
            std::swap(nums[high], nums[mid]);
            --high;
        }
        else
            ++mid;
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ 2, 0, 2, 1, 1, 0 };
    std::vector correct1{ 0, 0, 1, 1, 2, 2 };
    sortColors(test1);
    assert(test1 == correct1);

    std::vector test2{ 2, 0, 1 };
    std::vector correct2{ 0, 1, 2 };
    sortColors(test2);
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif