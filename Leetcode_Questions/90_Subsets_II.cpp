#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void subsetsWithDupHelper(std::vector<int>& nums, std::vector<std::vector<int>>& powerSet, std::vector<int>& subset, int start)
{
    powerSet.push_back(subset);
    for (int i{ start }; i < nums.size(); ++i)
    {
        // Skipping duplicates
        if (i > start && nums[i] == nums[i - 1])
            continue;

        subset.push_back(nums[i]);
        subsetsWithDupHelper(nums, powerSet, subset, i + 1);
        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<int> subset;
    std::vector<std::vector<int>> powerSet;
    subsetsWithDupHelper(nums, powerSet, subset, 0);
    return powerSet;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 2 };
    std::vector<std::vector<int>> answer1{ {}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2} };
    std::vector<std::vector<int>> result1{ subsetsWithDup(test1) };
    assert(answer1 == result1);

    std::vector<int> test2{ 0 };
    std::vector<std::vector<int>> answer2{ {}, {0} };
    std::vector<std::vector<int>> result2{ subsetsWithDup(test2) };
    assert(answer2 == result2);

    std::cout << "Success!\n";

    return 0;
}
#endif