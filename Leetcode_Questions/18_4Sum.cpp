#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// Regular 4Sum
# if 1
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> quadruplets;
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        for (int j{ i + 1 }; j < nums.size(); ++j)
        {
            long subtarget{ static_cast<long>(target) - nums[i] - nums[j] };
            int l{ j + 1 };
            int r{ static_cast<int>(nums.size()) - 1 };
            while (l < r)
            {
                if (nums[l] + nums[r] < subtarget)
                    ++l;
                else if (nums[l] + nums[r] > subtarget)
                    --r;
                else
                {
                    quadruplets.push_back({ nums[i], nums[j], nums[l], nums[r] });
                    ++l;
                    --r;
                    // Skipping duplicate nums[l]
                    while (l < r && nums[l - 1] == nums[l])
                        ++l;
                }
            }
            // Skipping duplicate nums[j]
            while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                ++j;
        }
        // Skipping duplicate nums[i]
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            ++i;
    }
    return quadruplets;
}
#endif

// 4Sum via kSum algorithm
#if 0
void kSumHelper(std::vector<int>& nums, std::vector<std::vector<int>>& sets, std::vector<int>& path, int l, int r, int k, long target)
{
    if (k == 2)
    {
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                path.push_back(nums[l]);
                path.push_back(nums[r]);
                sets.push_back(path);
                path.pop_back();
                path.pop_back();
                ++l;
                --r;
                // Skipping duplicate nums[l]
                while (l < r && nums[l] == nums[l - 1])
                {
                    ++l;
                }
            }
            else if (nums[l] + nums[r] > target)
                --r;
            else
                ++l;
        }
    }
    // Fixing k (the original k value) - 2 nums
    while (l < r)
    {
        path.push_back(nums[l]);
        kSumHelper(nums, sets, path, l + 1, r, k - 1, target - nums[l]);
        path.pop_back();
        // Skipping duplicate nums[l]
        while (l + 1 < r && nums[l] == nums[l + 1])
        {
            ++l;
        }
        ++l;
    }
}

std::vector<std::vector<int>> kSum(std::vector<int>& nums, int target, int k)
{
    sort(nums.begin(), nums.end());
    std::vector<int> path;
    path.reserve(k);
    std::vector<std::vector<int>> sets;
    kSumHelper(nums, sets, path, 0, static_cast<int>(nums.size()) - 1, k, target);
    return sets;
}

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    return kSum(nums, target, 4);
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector test1{ 1, 0, -1, 0, -2, 2 };
    std::vector<std::vector<int>> answer1{ {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1} };
    assert(fourSum(test1, 0) == answer1);

    std::vector<int> test2{ 2, 2, 2, 2, 2 };
    std::vector<std::vector<int>> answer2{ {2, 2, 2, 2} };
    assert(fourSum(test2, 8) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif