#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <unordered_set>


// easier-to-understand sliding window approach
#if 0
std::vector<int> findAnagrams(std::string s, std::string p)
{
    if (p.length() > s.length())
        return {};

    std::vector<int> indices;
    std::vector<int> freq(26, 0);
    std::unordered_set<char> chars;
    for (auto& c : p)
    {
        ++freq[c - 'a'];
        chars.insert(c);
    }
    int left{ 0 };
    int right{ static_cast<int>(p.length()) - 1 };
    for (int i{ 0 }; i < right; ++i)
    {
        --freq[s[i] - 'a'];
    }
    while (right < s.length())
    {
        --freq[s[right] - 'a'];
        bool found{ true };
        for (auto& c : chars)
        {
            if (freq[c - 'a'] != 0)
            {
                found = false;
                break;
            }
        }
        if (found)
            indices.push_back(left);

        ++freq[s[left] - 'a'];
        ++left;
        ++right;
    }
    return indices;
}
#endif

// More efficient sliding window approach
#if 1
std::vector<int> findAnagrams(std::string s, std::string p)
{
    int m{ static_cast<int>(p.length()) };
    std::vector<int> indices;
    std::vector<int> freq(26, 0);
    for (auto& c : p)
    {
        ++freq[c - 'a'];
    }
    int left{ 0 };
    int right{ 0 };
    while (right < s.length())
    {
        if (freq[s[right] - 'a'] > 0)
        {
            --freq[s[right] - 'a'];
            ++right;
            if (right - left == m)
                indices.push_back(left);
        }
        else
        {
            ++freq[s[left] - 'a'];
            ++left;
        }
    }
    return indices;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> correct1{ 0, 6 };
    assert(findAnagrams("cbaebabacd", "abc") == correct1);

    std::vector<int> correct2{ 0, 1, 2 };
    assert(findAnagrams("abab", "ab") == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif