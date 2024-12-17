#include <iostream>
#include <cassert>
#include <vector>

void backtrack(std::vector<int>& nums, int start, std::vector<int>& subset, std::vector<std::vector<int>>& power_set)
{
    power_set.push_back(subset);
    for (int i{ start }; i < nums.size(); ++i)
    {
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, power_set);
        subset.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums)
{
    std::vector<std::vector<int>> power_set{};
    std::vector<int> subset;
    backtrack(nums, 0, subset, power_set);
    return power_set;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3 };
    std::vector<std::vector<int>> correct1{ {}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3} };
    assert(subsets(test1) == correct1);

    std::vector<int> test2{ 0 };
    std::vector<std::vector<int>> correct2{ {}, {0} };
    assert(subsets(test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif