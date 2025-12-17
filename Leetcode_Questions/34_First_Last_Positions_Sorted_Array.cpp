#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> searchRange(std::vector<int>& nums, int target)
{
    if (nums.empty())
        return { -1, -1 };

    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };
    int mid{ low + (high - low) / 2 };
    std::vector<int> positions(2, -1);
    // Finding the first position
    while (low <= high)
    {
        if (nums[mid] == target)
        {
            positions[0] = mid;
            high = mid - 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;

        mid = low + (high - low) / 2;
    }
    if (positions[0] == -1)
        return positions;

    // Finding the last position
    low = mid;
    high = static_cast<int>(nums.size()) - 1;
    mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (nums[mid] == target)
        {
            positions[1] = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;

        mid = low + (high - low) / 2;
    }
    return positions;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 5, 7, 7, 8, 8, 10 };
    std::vector<int> answer1{ 3, 4 };
    assert(searchRange(test1, 8) == answer1);

    std::vector<int> test2{ 5, 7, 7, 8, 8, 10 };
    std::vector<int> answer2{ -1, -1 };
    assert(searchRange(test2, 6) == answer2);

    std::vector<int> test3{};
    std::vector<int> answer3{ -1, -1 };
    assert(searchRange(test3, 0) == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif