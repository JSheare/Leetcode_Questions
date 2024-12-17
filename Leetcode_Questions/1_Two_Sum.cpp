#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> numsMap;
	for (int i{ 0 }; i < nums.size(); ++i)
	{
		int diff{ target - nums[i] };
		if (numsMap.count(diff))
		{
			return { numsMap[diff], i };
		}

		numsMap[nums[i]] = i;
	}

	return {};
}

#if 0
int main()
{
	// Provided test cases
	std::vector test1{ 2, 7, 11, 15 };
	std::vector answer1{ 0, 1 };
	assert(answer1 == twoSum(test1, 9));

	std::vector test2{ 3, 2, 4 };
	std::vector answer2{ 1, 2 };
	assert(answer2 == twoSum(test2, 6));

	std::vector test3{ 3, 3 };
	std::vector answer3{ 0, 1 };
	assert(answer3 == twoSum(test3, 6));

	std::cout << "Success!\n";

	return 0;
}
#endif