#include <iostream>
#include <cassert>
#include <string>

int strStr(std::string haystack, std::string needle)
{
    if (needle.size() > haystack.size())
        return -1;

    for (int i{ 0 }; i <= haystack.size() - needle.size(); ++i)
    {
        int j{ 0 };
        while (j < needle.size() && haystack[i + j] == needle[j])
        {
            ++j;
        }
        if (j == needle.size())
            return i;
    }
    return -1;
}

#if 0
int main()
{
    // Provided test cases
    assert(strStr("sadbutsad", "sad") == 0);

    assert(strStr("leetcode", "leeto") == -1);

    std::cout << "Success!\n";

    return 0;
}
#endif