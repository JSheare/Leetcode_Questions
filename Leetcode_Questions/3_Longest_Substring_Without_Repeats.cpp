#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <string>

int lengthOfLongestSubstring(std::string s)
{
    if (s.length() == 0)
        return 0;

    std::vector<int> seen(127, -1);  //127 is the max (non-extended) Ascii value
    int maxLength{ 0 };
    int left{ 0 };
    for (int right{ 0 }; right < s.length(); ++right)
    {
        char c{ s[right] };
        if (seen[c] >= left)
            left = seen[c] + 1;
        else
            maxLength = std::max(maxLength, right - left + 1);

        seen[c] = right;
    }
    return maxLength;
}

#if 0
int main()
{
    // Provided test cases
    assert(lengthOfLongestSubstring("abcabcbb") == 3);

    assert(lengthOfLongestSubstring("bbbbb") == 1);

    assert(lengthOfLongestSubstring("pwwkew") == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif