#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void pUBacktrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<char>& used, std::vector<int>& perm)
{
    if (perm.size() == nums.size())
    {
        result.push_back(perm);
        return;
    }
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        perm.push_back(nums[i]);
        used[i] = 1;
        pUBacktrack(nums, result, used, perm);
        used[i] = 0;
        perm.pop_back();
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<int> perm;
    std::vector<char> used(nums.size(), 0);
    pUBacktrack(nums, result, used, perm);
    return result;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 1, 2 };
    std::vector<std::vector<int>> answer1{
        {1, 1, 2},
        {1, 2, 1},
        {2, 1, 1},
    };
    assert(permuteUnique(test1) == answer1);

    std::vector<int> test2{ 1, 2, 3 };
    std::vector<std::vector<int>> answer2{
        {1, 2, 3},
        {1, 3, 2},
        {2, 1, 3},
        {2, 3, 1},
        {3, 1, 2},
        {3, 2, 1}
    };
    assert(permuteUnique(test2) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif