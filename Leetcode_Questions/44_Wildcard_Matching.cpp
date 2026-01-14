#include <iostream>
#include <cassert>
#include <vector>
#include <string>

// Dynamic programming solution (similar to question 10)
#if 0
bool isMatch(std::string s, std::string p)
{
    // dp[i][j] describes if the substring from 0 to i - 1 is a match with the subpattern from 0 to j - 1
    std::vector<std::vector<char>> dp(s.size() + 1, std::vector<char>(p.size() + 1, 0));
    dp[0][0] = 1;
    // A star at the beginning will always match anything, including an empty string
    for (int j{ 0 }; j < p.size() && p[j] == '*'; ++j)
    {
        dp[0][j + 1] = 1;
    }
    for (int i{ 1 }; i <= s.size(); ++i)
    {
        for (int j{ 1 }; j <= p.size(); ++j)
        {
            if (p[j - 1] == '*')
                // At each stage, we either attempt to match another character or consume the star
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                // Straightforward character match with wildcard support
                dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
        }
    }
    return dp[s.size()][p.size()];
}
#endif

// Greedy two pointer solution
#if 1
bool isMatch(std::string s, std::string p)
{
    int i{ 0 };
    int j{ 0 };
    int sTemp{ -1 };
    int starIndex{ -1 };
    while (i < s.size())
    {
        if (j < p.size() && (p[j] == s[i] || p[j] == '?'))
        {
            ++i;
            ++j;
        }
        else if (j < p.size() && p[j] == '*')
        {
            starIndex = j;
            sTemp = i;
            ++j;
        }
        else if (starIndex != -1)
        {
            j = starIndex + 1;
            ++sTemp;
            i = sTemp;
        }
        else
            return false;
    }
    while (j < p.size() && p[j] == '*')
    {
        ++j;
    }
    return j == p.size();
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(isMatch("aa", "a") == false);

    assert(isMatch("aa", "*") == true);

    assert(isMatch("cb", "?a") == false);

    std::cout << "Success!\n";

    return 0;
}
#endif