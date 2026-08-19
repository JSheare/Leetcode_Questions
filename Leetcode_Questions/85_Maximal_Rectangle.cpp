#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>

int maximalRectangle(std::vector<std::vector<char>>& matrix)
{
    // This solution is kind of an extension of the one from "Largest Rectangle in Histogram"
    // The big difference is that we make/update the histogram with info from each row of the matrix as we go
    int rowLen{ static_cast<int>(matrix[0].size()) };
    int maxArea{ 0 };
    std::vector<int> dp(rowLen, 0);
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        std::stack<int> st;
        for (int j{ 0 }; j <= rowLen; ++j)
        {
            // Updating the "histogram" (dp array)
            if (j < rowLen)
            {
                if (matrix[i][j] == '1')
                    ++dp[j];
                else
                    dp[j] = 0;
            }
            // Looking for the largest rectangle at this point
            int currHeight{ j == dp.size() ? 0 : dp[j] };
            while (!st.empty() && dp[st.top()] > currHeight)
            {
                int height{ dp[st.top()] };
                st.pop();
                maxArea = std::max((st.empty() ? j : j - st.top() - 1) * height, maxArea);
            }
            st.push(j);
        }
    }
    return maxArea;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> test1{
        {'1', '0', '1', '0', '0'},
        {'1','0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'} };
    assert(maximalRectangle(test1) == 6);

    std::vector<std::vector<char>> test2{
        {'0'} };
    assert(maximalRectangle(test2) == 0);

    std::vector<std::vector<char>> test3{
        {'1'} };
    assert(maximalRectangle(test3) == 1);


    std::cout << "Success!\n";

    return 0;
}
#endif