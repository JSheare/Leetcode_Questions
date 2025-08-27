#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int LIPSolve(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& dp, int prev, int i, int j)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] <= prev)
        return 0;

    if (dp[i][j])
        return dp[i][j];

    dp[i][j] = 1 + std::max({ LIPSolve(matrix, dp, matrix[i][j], i + 1, j),
                              LIPSolve(matrix, dp, matrix[i][j], i - 1, j),
                              LIPSolve(matrix, dp, matrix[i][j], i, j + 1),
                              LIPSolve(matrix, dp, matrix[i][j], i, j - 1) });
    return dp[i][j];
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
{
    int maxPath{ 0 };
    std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size()));
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        for (int j{ 0 }; j < matrix[0].size(); ++j)
        {
            maxPath = std::max(maxPath, LIPSolve(matrix, dp, -1, i, j));
        }
    }
    return maxPath;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {9, 9, 4},
                                         {6, 6, 8},
                                         {2, 1, 1} };
    assert(longestIncreasingPath(test1) == 4);

    std::vector<std::vector<int>> test2{ {3, 4, 5},
                                         {3, 2, 6},
                                         {2, 2, 1} };
    assert(longestIncreasingPath(test2) == 4);

    std::vector<std::vector<int>> test3 = { {1} };
    assert(longestIncreasingPath(test3) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif