#include <iostream>
#include <assert.h>
#include <vector>

void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, std::vector<int>& perm, std::vector<bool>& used)
{
	if (perm.size() == nums.size())
	{
		result.push_back(perm);
		return;
	}

	for (int i{ 0 }; i < nums.size(); ++i)
	{
		if (used[i])
			continue;
		
		perm.push_back(nums[i]);
		used[i] = true;
		backtrack(nums, result, perm, used);
		used[i] = false;
		perm.pop_back();
	}
}

std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
	std::vector<std::vector<int>> result;
	std::vector<int> perm;
	std::vector<bool> used(nums.size(), false);
	backtrack(nums, result, perm, used);
	return result;
}

#if 0
int main()
{
	// Provided test cases
	std::vector<int> test1{ 1, 2, 3 };
	std::vector<std::vector<int>> answer1{ permute(test1) };
	std::vector<std::vector<int>> correctAnswer1{ {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} };
	assert(answer1 == correctAnswer1);

	std::vector<int> test2{ 0, 1 };
	std::vector<std::vector<int>> answer2{ permute(test2) };
	std::vector<std::vector<int>> correctAnswer2{ {0, 1}, {1, 0} };
	assert(answer2 == correctAnswer2);

	std::vector<int> test3{ 1 };
	std::vector<std::vector<int>> answer3{ permute(test3) };
	std::vector<std::vector<int>> correctAnswer3{ {1} };
	assert(answer3 == correctAnswer3);

	std::cout << "Success!\n";

	return 0;
}
#endif