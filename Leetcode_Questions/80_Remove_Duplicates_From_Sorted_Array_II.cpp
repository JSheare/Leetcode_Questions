#include <iostream>
#include <cassert>
#include <vector>

int removeDuplicates(std::vector<int>& nums)
{
    if (nums.size() <= 2)
        return static_cast<int>(nums.size());

    int left{ 2 };
    for (int right{ 2 }; right < nums.size(); ++right)
    {
        if (nums[left - 2] != nums[right])
        {
            nums[left] = nums[right];
            ++left;
        }
    }
    return left;
}

void testRemoveDuplicates(std::vector<int>& expected, std::vector<int>& nums, int k)
{
    assert(k == expected.size());

    for (int i{ 0 }; i < k; ++i)
    {
        assert(nums[i] == expected[i]);
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 1, 1, 2, 2, 3 };
    std::vector<int> answer1{ 1, 1, 2, 2, 3 };
    int result1{ removeDuplicates(test1) };
    testRemoveDuplicates(answer1, test1, result1);

    std::vector<int> test2{ 0, 0, 1, 1, 1, 1, 2, 3, 3 };
    std::vector<int> answer2{ 0, 0, 1, 1, 2, 3, 3 };
    int result2{ removeDuplicates(test2) };
    testRemoveDuplicates(answer2, test2, result2);

    std::cout << "Success!\n";

    return 0;
}
#endif