#include <iostream>
#include <cassert>
#include <string>
#include <vector>

std::string minWindow(std::string s, std::string t)
{
    if (s.length() < t.length())
        return "";

    std::vector<int> freq(256, 0);
    for (auto& c : t)
    {
        ++freq[c];
    }
    int left{ 0 };
    int count{ 0 };
    int minStart{ -1 };
    int minLen{ INT_MAX };
    for (int right{ 0 }; right < s.length(); ++right)
    {
        if (freq[s[right]] > 0)
            ++count;

        --freq[s[right]];
        while (count == t.length())
        {
            if (right - left + 1 < minLen)
            {
                minStart = left;
                minLen = right - left + 1;
            }
            ++freq[s[left]];
            if (freq[s[left]] > 0)
                --count;

            ++left;
        }
    }
    return minStart == -1 ? "" : s.substr(minStart, minLen);
}

#if 0
int main()
{
    // Provided test cases
    assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");

    assert(minWindow("a", "a") == "a");

    assert(minWindow("a", "aa") == "");

    std::cout << "Success!\n";

    return 0;
}
#endif