#include <iostream>
#include <assert.h>
#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int i, int j)
{
    if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}

int numIslands(std::vector<std::vector<char>>& grid)
{
    int count{ 0 };
    for (int i{ 0 }; i < grid.size(); ++i)
    {
        for (int j{ 0 }; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                ++count;
            }
        }
    }
    return count;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> test1{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'} };
    assert(numIslands(test1) == 1);

    std::vector<std::vector<char>> test2{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'} };
    assert(numIslands(test2) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif