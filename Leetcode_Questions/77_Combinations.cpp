#include <iostream>
#include <cassert>
#include <vector>

void combineHelper(std::vector<std::vector<int>>& combos, std::vector<int>& combo, int n, int k, int i)
{
    if (combo.size() == k)
    {
        combos.push_back(combo);
        return;
    }
    for (i; i <= n; ++i)
    {
        combo.push_back(i);
        combineHelper(combos, combo, n, k, i + 1);
        combo.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k)
{
    std::vector<std::vector<int>> combos;
    std::vector<int> combo;
    combineHelper(combos, combo, n, k, 1);
    return combos;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> answer1{ {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4} };
    assert(combine(4, 2) == answer1);

    std::vector<std::vector<int>> answer2{ {1} };
    assert(combine(1, 1) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif