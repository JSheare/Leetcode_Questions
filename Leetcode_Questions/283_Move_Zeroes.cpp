#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

void moveZeroes(std::vector<int>& nums)
{
    if (nums.size() == 1)
        return;

    int left{ 0 };
    for (int right{ 0 }; right < nums.size(); ++right)
    {
        if (nums[right] != 0)
        {
            std::swap(nums[left], nums[right]);
            ++left;
        }
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 0, 1, 0, 3, 12 };
    std::vector<int> correct1{ 1, 3, 12, 0, 0 };
    moveZeroes(test1);
    assert(test1 == correct1);

    std::vector<int> test2{ 0 };
    std::vector<int> correct2{ 0 };
    moveZeroes(test2);
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif