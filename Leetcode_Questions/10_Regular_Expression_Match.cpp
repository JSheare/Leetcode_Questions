#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstdint>

// Recursive solution
# if 0
bool isMatch(int i, std::string& s, int j, std::string& p)
{
    int sLen{ static_cast<int>(s.size()) };
    int pLen{ static_cast<int>(p.size()) };
    // If we've exhausted the pattern and the string, then we've got a whole string match
    if (j == pLen)
        return i == sLen;

    if (p[j + 1] == '*')
    {
        /*
        This one liner is basically just case1 || case2
        case1 = isMatch(i, s, j + 2, p), which corresponds to a zero character match.
        case2 = i < sLen && (p[j] == '.' || s[i] == p[j]) && isMatch(i + 1, s, j, p), which corresponds to a
            one or more character match. This match case happens when we still have string left to match
            (i < sLen), the current string character is a match (p[i] == '.' || s[i] == p[j]), and the rest of the
            string is a match for the pattern starting at this '*' (isMatch(i + 1, s, j, p)).
        */
        if (isMatch(i, s, j + 2, p) || i < sLen && (p[j] == '.' || s[i] == p[j]) && isMatch(i + 1, s, j, p))
            return true;
    }
    // This is just a straightforward character match, taking the '.' wildcard character into account
    else if (i < sLen && (p[j] == '.' || s[i] == p[j]) && isMatch(i + 1, s, j + 1, p))
        return true;

    return false;
}

bool isMatch(std::string s, std::string p)
{
    return isMatch(0, s, 0, p);
}
#endif

// Bottom up dynamic programming solution. Derived from the recursive solution above
#if 1
bool isRegexMatch(std::string s, std::string p)
{
    int sLen{ static_cast<int>(s.size()) };
    int pLen{ static_cast<int>(p.size()) };
    std::vector<std::vector<uint8_t>> dp(sLen + 1, std::vector<uint8_t>(pLen + 1));
    dp[sLen][pLen] = 1;
    for (int i{ sLen }; i >= 0; --i)
    {
        for (int j{ pLen - 1 }; j >= 0; --j)
        {
            if (p[j + 1] == '*')
                dp[i][j] = uint8_t(dp[i][j + 2] || i < sLen && (p[j] == '.' || s[i] == p[j]) && dp[i + 1][j]);
            else
                dp[i][j] = uint8_t(i < sLen && (p[j] == '.' || s[i] == p[j]) && dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(isRegexMatch("aa", "a") == false);

    assert(isRegexMatch("aa", "a*") == true);

    assert(isRegexMatch("ab", ".*") == true);

    std::cout << "Success!\n";

    return 0;
}
#endif