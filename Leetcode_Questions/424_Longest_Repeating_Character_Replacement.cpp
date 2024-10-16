#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <algorithm>

int characterReplacement(std::string s, int k)
{
    if (s.length() == 1)
        return 1;

    int left{ 0 };
    int right{ 0 };
    int maxFreq{ 0 };
    std::vector<int> charFreq(26);
    for (; right < s.length(); ++right)
    {
        // Expanding the window
        ++charFreq[s[right] - 'A'];
        maxFreq = std::max(maxFreq, charFreq[s[right] - 'A']);
        // If the number of characters we need to replace (those that aren't the one corresponding to maxFreq)
        // is larger than k, then we need to shrink the window
        if ((right - left + 1) - maxFreq > k)
        {
            --charFreq[s[left] - 'A'];
            ++left;
        }
    }
    // Length of the window we've settled on. No +1 needed b/c right will be past the max index
    return right - left;
}

#if 0
int main()
{
    //Provided test cases
    assert(characterReplacement("ABAB", 2) == 4);

    assert(characterReplacement("AABABBA", 1) == 4);

    std::cout << "Success!\n";

    return 0;
}
#endif