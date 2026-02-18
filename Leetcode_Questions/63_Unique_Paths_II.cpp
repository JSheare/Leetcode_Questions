#include <iostream>
#include <cassert>
#include <vector>

// Recursive bottom-up dp
# if 0
int traverseObstacles(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& dp, int i, int j)
{
    if (i == grid.size() || j == grid[0].size() || grid[i][j] == 1)
        return 0;

    if (i == grid.size() - 1 && j == grid[0].size() - 1)
        return 1;

    if (dp[i][j] == -1)
    {
        dp[i][j] = traverseObstacles(grid, dp, i + 1, j) + traverseObstacles(grid, dp, i, j + 1);
    }
    return dp[i][j];
}

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    std::vector<std::vector<int>> dp(obstacleGrid.size(), std::vector(obstacleGrid[0].size(), -1));
    return traverseObstacles(obstacleGrid, dp, 0, 0);
}
#endif

// Iterative space-optimized bottom-up dp
#if 1
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
{
    std::vector<long long> dp(obstacleGrid[0].size(), 0);
    dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i{ 0 }; i < obstacleGrid.size(); ++i)
    {
        for (int j{ 0 }; j < obstacleGrid[0].size(); ++j)
        {
            if (obstacleGrid[i][j] == 1)
                dp[j] = 0;

            else if (j > 0)
                dp[j] += dp[j - 1];
        }
    }
    return static_cast<int>(dp[obstacleGrid[0].size() - 1]);
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0} };
    assert(uniquePathsWithObstacles(test1) == 2);

    std::vector<std::vector<int>> test2{
        {0, 1},
        {0, 0} };
    assert(uniquePathsWithObstacles(test2) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif