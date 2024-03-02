#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

bool isAnagram(const std::string& s, const std::string& t)
{
    if (s.length() != t.length())
        return false;

    std::vector<int> freq(26, 0);
    for (int i{ 0 }; i < s.length(); ++i)
    {
        ++freq[s[i] - 'a'];
        --freq[t[i] - 'a'];
    }
    for (int i{ 0 }; i < freq.size(); ++i)
    {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

# if 0
int main()
{
    // Provided test cases
    std::string test1Str1{ "anagram" };
    std::string test1Str2{ "nagaram" };
    bool answer1{ true };
    assert(isAnagram(test1Str1, test1Str2) == answer1);

    std::string test2Str1{ "rat" };
    std::string test2Str2{ "car" };
    bool answer2{ false };
    assert(isAnagram(test2Str1, test2Str2) == answer2);

    std::cout << "Success!\n";

	return 0;
}
#endif
