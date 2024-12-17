#include <iostream>
#include <cassert>
#include <string>

int lengthFromCenter(std::string& s, int left, int right)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        --left;
        ++right;
    }
    return (right - 1) - (left + 1) + 1;
}

std::string longestPalindrome(std::string s)
{
    int maxLen{ 0 };
    int maxInd{ 0 };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        int len;
        len = lengthFromCenter(s, i, i);
        if (len > maxLen)
        {
            maxLen = len;
            maxInd = i;
        }
        len = lengthFromCenter(s, i, i + 1);
        if (len > maxLen)
        {
            maxLen = len;
            maxInd = i + 1;
        }

    }
    return s.substr(maxInd - maxLen / 2, maxLen);
}

#if 0
int main()
{
    // Provided test cases
    assert(longestPalindrome("babad") == "bab" || longestPalindrome("babad") == "aba");

    assert(longestPalindrome("cbbd") == "bb");

    std::cout << "Success!\n";

    return 0;
}
#endif