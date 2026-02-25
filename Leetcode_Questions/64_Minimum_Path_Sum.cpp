#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid)
{
    std::vector<int> dp(grid[0].size(), 0);
    for (int i{ 0 }; i < grid.size(); ++i)
    {
        dp[0] = dp[0] + grid[i][0];
        for (int j{ 1 }; j < grid[0].size(); ++j)
        {
            if (i > 0)
                dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
            else
                dp[j] = dp[j - 1] + grid[i][j];
        }
    }
    return dp[grid[0].size() - 1];
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1} };
    assert(minPathSum(test1) == 7);

    std::vector<std::vector<int>> test2{
        {1, 2, 3},
        {4, 5, 6} };
    assert(minPathSum(test2) == 12);

    std::cout << "Success!\n";

    return 0;
}
#endif