#include <iostream>
#include <cassert>
#include <vector>

int traverse(std::vector<std::vector<int>>& grid, int i, int j)
{
    if (i == grid.size() || j == grid[0].size())  // Off the grid
        return 0;

    if (i == grid.size() - 1 && j == grid[0].size() - 1)  // In the bottom right corner
        return 1;

    if (grid[i][j] == -1)  // Haven't visited this cell yet
    {
        grid[i][j] = traverse(grid, i + 1, j) + traverse(grid, i, j + 1);
    }
    return grid[i][j];
}

// This could be optimized by only keeping the prev row and the current row
// It might also be possible to basically just calculate the solution with combinatorics, but I haven't checked
int uniquePaths(int m, int n)
{
    std::vector<std::vector<int>> grid(m, std::vector<int>(n, -1));
    return traverse(grid, 0, 0);
}

#if 0
int main()
{
    // Provided test cases
    assert(uniquePaths(3, 7) == 28);

    assert(uniquePaths(3, 2) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif