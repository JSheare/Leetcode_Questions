#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void cS2Backtrack(std::vector<int>& candidates, std::vector<std::vector<int>>& combos, std::vector<int>& combo, int index, int target)
{
    if (target == 0)
    {
        combos.push_back(combo);
        return;
    }
    for (int i{ index }; i < candidates.size(); ++i)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            return;

        combo.push_back(candidates[i]);
        cS2Backtrack(candidates, combos, combo, i + 1, target - candidates[i]);
        combo.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> combos;
    std::vector<int> combo;
    cS2Backtrack(candidates, combos, combo, 0, target);
    return combos;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 10, 1, 2, 7, 6, 1, 5 };
    std::vector<std::vector<int>> answer1{ {1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6} };
    assert(combinationSum2(test1, 8) == answer1);

    std::vector<int> test2{ 2, 5, 2, 1, 2 };
    std::vector<std::vector<int>> answer2{ {1, 2, 2}, {5} };
    assert(combinationSum2(test2, 5) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif