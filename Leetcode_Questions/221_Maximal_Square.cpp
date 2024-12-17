#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

// Standard dynamic programming solution
#if 0
int maximalSquare(std::vector<std::vector<char>>& matrix)
{
    if (matrix.size() == 0)
        return 0;

    std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    int maxSide{ 0 };
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        for (int j{ 0 }; j < matrix[0].size(); ++j)
        {
            if (!i || !j || matrix[i][j] == '0')
                dp[i][j] = matrix[i][j] - '0';
            else
                // Checking the diagonal, left, and top values to see if we can make a new square or expand an existing one
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j])) + 1;

            maxSide = std::max(maxSide, dp[i][j]);
        }
    }
    return maxSide * maxSide;
}
#endif

// Space-optimized dynamic programming solution
#if 1
int maximalSquare(std::vector<std::vector<char>>& matrix)
{
    if (matrix.size() == 0)
        return 0;

    std::vector<int> curr(matrix[0].size(), 0);
    int prev{ 0 };
    int maxSide{ 0 };
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        for (int j{ 0 }; j < matrix[0].size(); ++j)
        {
            // Temporarily storing the previous row's value for this column
            // This will be the diagonal for the next value in the current row
            int temp{ curr[j] };
            if (!i || !j || matrix[i][j] == '0')
                curr[j] = matrix[i][j] - '0';
            else
                // Checking the diagonal (prev), left, and top values to see if we can make a new square 
                // or expand an existing one
                curr[j] = std::min(prev, std::min(curr[j - 1], curr[j])) + 1;

            maxSide = std::max(maxSide, curr[j]);
            prev = temp;
        }
    }
    return maxSide * maxSide;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> test1{ 
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'} };
    assert(maximalSquare(test1) == 4);

    std::vector<std::vector<char>> test2{
        {'0', '1'},
        {'1', '0'} };
    assert(maximalSquare(test2) == 1);

    std::vector<std::vector<char>> test3{
        {'0'} };
    assert(maximalSquare(test3) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif