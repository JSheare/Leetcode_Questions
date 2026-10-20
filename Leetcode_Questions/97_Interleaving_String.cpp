#include <iostream>
#include <cassert>
#include <vector>
#include <string>

// Bottom-up dynamic programming solution
#if 0
bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if (s3.size() != s1.size() + s2.size())
        return false;

    // dp[i][j] represents whether the first i chars of s1 and the first j chars of s2 can interleave 
    // to make the first i + j chars of s3
    std::vector<std::vector<char>> dp(s1.size() + 1, std::vector(s2.size() + 1, ' '));
    // Empty strings always interleave
    dp[0][0] = true;

    // Initializing the first column (no chars from s2)
    for (int i{ 1 }; i <= s1.size(); ++i)
    {
        dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);
    }

    // Initializing the first row (no chars from s1)
    for (int j{ 1 }; j <= s2.size(); ++j)
    {
        dp[0][j] = dp[0][j - 1] && (s3[j - 1] == s2[j - 1]);
    }

    // Filling out the rest of the table
    for (int i{ 1 }; i <= s1.size(); ++i)
    {
        for (int j{ 1 }; j <= s2.size(); ++j)
        {
            dp[i][j] = (dp[i - 1][j] && s3[(i + j) - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[(i + j) - 1] == s2[j - 1]);
        }
    }
    return dp[s1.size()][s2.size()];
}
#endif

// Space-optimized bottom-up dynamic programming solution
#if 1
bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if (s3.size() != s1.size() + s2.size())
        return false;

    if (s2.size() > s1.size())
        return isInterleave(s2, s1, s3);

    std::vector<char> dp(s1.size() + 1, ' ');
    // Empty strings always interleave
    dp[0] = true;

    // Setting up the first row (no chars from s1)
    for (int j{ 1 }; j <= s2.size(); ++j)
    {
        dp[j] = dp[j - 1] && (s3[j - 1] == s2[j - 1]);
    }

    // Updating the table as we go
    for (int i{ 1 }; i <= s1.size(); ++i)
    {
        dp[0] = dp[0] && s3[i - 1] == s1[i - 1];
        for (int j{ 1 }; j <= s2.size(); ++j)
        {
            dp[j] = (dp[j] && s3[(i + j) - 1] == s1[i - 1]) || (dp[j - 1] && s3[(i + j) - 1] == s2[j - 1]);
        }
    }
    return dp[s2.size()];
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);

    assert(isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);

    assert(isInterleave("", "", "") == true);

    std::cout << "Success!\n";
    
    return 0;
}
#endif