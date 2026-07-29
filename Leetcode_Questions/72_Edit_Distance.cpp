#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

// Bottom-up dynamic programming solution
#if 0
int minDistance(std::string word1, std::string word2)
{
    if (word1.size() == 0 || word2.size() == 0)
        return static_cast<int>(std::max(word1.size(), word2.size()));

    if (word1 == word2)
        return 0;

    // Dynamic programming array. Each element d[i][j] of the array is the minimum edit distance between the first
    // i characters of word1 and the first j characters of word2
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
    for (int i{ 0 }; i <= word1.size(); ++i)
    {
        for (int j{ 0 }; j <= word2.size(); ++j)
        {
            // For the first two, the number of changes to go from an empty string to n is always n
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            // If the two characters match, then no change is necessary
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                // Each of the operations in min: replace, insert, delete
                dp[i][j] = 1 + std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }
    return dp[word1.size()][word2.size()];
}
#endif

// Space-optimized bottom-up dynamic programming solution
#if 1
int minDistance(std::string word1, std::string word2)
{
    if (word1.size() == 0 || word2.size() == 0)
        return static_cast<int>(std::max(word1.size(), word2.size()));

    if (word1 == word2)
        return 0;

    std::vector<int> prev(word2.size() + 1, 0);
    std::vector<int> curr(word2.size() + 1, 0);
    for (int i{ 0 }; i <= word1.size(); ++i)
    {
        for (int j{ 0 }; j <= word2.size(); ++j)
        {
            if (i == 0)
                curr[j] = j;
            else if (j == 0)
                curr[j] = i;
            else if (word1[i - 1] == word2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + std::min(prev[j - 1], std::min(curr[j - 1], prev[j]));
        }
        std::swap(prev, curr);
    }
    return prev[word2.size()];
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(minDistance("horse", "ros") == 3);

    assert(minDistance("intention", "execution") == 5);

    std::cout << "Success!\n";

    return 0;
}
#endif