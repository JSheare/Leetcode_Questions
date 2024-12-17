#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> answer;
    for (int i{ 0 }; i < nums.size() - 2; ++i)
    {
        if (nums[i] > 0)
            break;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l{ i + 1 };
        int r{ static_cast<int>(nums.size()) - 1 };
        while (l < r)
        {
            int total = nums[i] + nums[l] + nums[r];
            if (total < 0)
                ++l;
            else if (total > 0)
                --r;
            else
            {
                std::vector<int> triplet{ nums[i], nums[l], nums[r] };
                answer.push_back(triplet);
                while (l < r && nums[l] == triplet[1]) { ++l; }
                while (l < r && nums[r] == triplet[2]) { --r; }
            }
        }
    }
    return answer;
}

// A more general answer with a target parameter
#if 0
std::vector<std::vector<int>> threeSum(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> answer;
    for (int i{ 0 }; i < nums.size() - 2; ++i)
    {
        int l{ i + 1 };
        int r{ static_cast<int>(nums.size()) - 1 };
        while (l < r)
        {
            int total{ nums[i] + nums[l] + nums[r] };
            if (total < target)
                ++l;
            else if (total > target)
                --r;
            else
            {
                std::vector<int> triplet{ nums[i], nums[l], nums[r] };
                answer.push_back(triplet);
                while (l < r && nums[l] == triplet[1]) { ++l; }
                while (l < r && nums[r] == triplet[2]) { --r; }
            }
        }
    }
    return answer;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ -1, 0, 1, 2, -1, -4 };
    std::vector<std::vector<int>> correct1{ {-1, -1, 2}, {-1, 0, 1} };
    assert(threeSum(test1) == correct1);

    std::vector<int> test2{ 0, 1, 1 };
    std::vector<std::vector<int>> correct2{};
    assert(threeSum(test2) == correct2);

    std::vector<int> test3{ 0, 0, 0};
    std::vector<std::vector<int>> correct3{ {0, 0, 0}};
    assert(threeSum(test3) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif