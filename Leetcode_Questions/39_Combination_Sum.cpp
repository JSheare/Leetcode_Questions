#include <iostream>
#include <cassert>
#include <vector>

void backtrack(int index, std::vector<int>& candidates, int target, std::vector<int>& combo, std::vector<std::vector<int>>& result)
{
	if (target == 0)
	{
		result.push_back(combo);
		return;
	}
	if (target < 0 || index == candidates.size())
		return;
	
	combo.push_back(candidates[index]);
	backtrack(index, candidates, target - candidates[index], combo, result);
	combo.pop_back();
	backtrack(index + 1, candidates, target, combo, result);
	return;
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
	std::vector<std::vector<int>> result;
	std::vector<int> combo;
	backtrack(0, candidates, target, combo, result);
	return result;
}

#if 0
int main()
{
	// Provided test cases
	std::vector<int> test1{ 2, 3, 6, 7 };
	std::vector<std::vector<int>> answer1{ combinationSum(test1, 7) };
	std::vector<std::vector<int>> correctAnswer1{ {2, 2, 3}, {7} };
	assert(answer1 == correctAnswer1);

	std::vector<int> test2{ 2, 3, 5 };
	std::vector<std::vector<int>> answer2{ combinationSum(test2, 8) };
	std::vector<std::vector<int>> correctAnswer2{ {2, 2, 2, 2}, {2, 3, 3}, {3, 5} };
	assert(answer2 == correctAnswer2);

	std::vector<int> test3{ 2 };
	std::vector<std::vector<int>> answer3{ combinationSum(test3, 1) };
	std::vector<std::vector<int>> correctAnswer3{};
	assert(answer3 == correctAnswer3);

	std::cout << "Success!\n";

	return 0;
}
#endif