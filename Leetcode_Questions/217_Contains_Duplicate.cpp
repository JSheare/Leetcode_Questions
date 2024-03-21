#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    for (int i{ 1 }; i < nums.size(); ++i)
    {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}

// Another solution that uses a set instead. This one is faster (O(n) vs. O(nlogn)), but uses more memory
//bool containsDeuplicate(std::vector<int>& nums)
//{
//    std::unordered_set<int> values;
//    values.reserve(nums.size());
//        for (int num : nums)
//        {
//            if (values.find(num) != values.end())
//                return true;
//
//            values.insert(num);
//        }
//    return false;
//}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3, 1 };
    assert(containsDuplicate(test1) == true);

    std::vector<int> test2{ 1, 2, 3, 4 };
    assert(containsDuplicate(test2) == false);

    std::vector<int> test3{ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    assert(containsDuplicate(test3) == true);

    std::cout << "Success!\n";

	return 0;
}
#endif