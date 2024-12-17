#include <iostream>
#include <cassert>
#include <vector>
#include <string>

// Dynamic programming solution
#if 0
int numDecodings(std::string s)
{
    if (s[0] == '0')
        return 0;

    std::vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i{ 2 }; i <= s.length(); ++i)
    {
        int lenOne{ s[i - 1] - '0' };
        int lenTwo{ std::stoi(s.substr(i - 2, 2)) };
        if (lenOne != 0)
            dp[i] += dp[i - 1];

        if (10 <= lenTwo && lenTwo <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.size()];
}
#endif

// Space-optimized dynamic programming solution
#if 1
int numDecodings(std::string s)
{
    if (s[0] == '0')
        return 0;

    int prevPrev{ 1 };
    int prev{ 1 };
    int curr{ 0 };
    for (int i{ 2 }; i <= s.length(); ++i)
    {
        int lenOne{ s[i - 1] - '0' };
        int lenTwo{ std::stoi(s.substr(i - 2, 2)) };
        if (lenOne != 0)
            curr += prev;

        if (10 <= lenTwo && lenTwo <= 26)
        {
            curr += prevPrev;
        }
        prevPrev = prev;
        prev = curr;
        curr = 0;
    }
    return prev;
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(numDecodings("12") == 2);

    assert(numDecodings("226") == 3);

    assert(numDecodings("06") == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif