#include <iostream>
#include <assert.h>
#include <string>
#include <unordered_map>
#include <vector>

int longestPalindrome(std::string s)
{
    std::unordered_map<char, int> freq{};
    for (char c : s)
    {
        ++freq[c];
    }


    int sum{ 0 };
    bool single{ false };
    for (auto i : freq)
    {
        if (i.second % 2 == 0)
            sum += i.second;
        else
        {
            if (i.second > 1)
                sum += i.second - 1;

            if (!single)
            {
                ++sum;
                single = true;
            }
        }
    }
    return sum;
}

// Another solution that uses vectors instead of an unordered map. A little slower, but more memory-efficient
//int longestPalindrome(string s)
//{
//    std::vector<int> lowerFreq(26, 0);
//    std::vector <int> upperFreq(26, 0);
//    for (char c : s)
//    {
//        if (isupper(c))
//            ++upperFreq[c - 'A'];
//        else
//            ++lowerFreq[c - 'a'];
//    }
//
//    int sum{ 0 };
//    bool single{ false };
//    for (int i{ 0 }; i < 26; ++i)
//    {
//        if (lowerFreq[i] % 2 == 0)
//        {
//            sum += lowerFreq[i];
//        }
//        else
//        {
//            if (lowerFreq[i] > 1)
//                sum += lowerFreq[i] - 1;
//
//            if (!single)
//            {
//                ++sum;
//                single = true;
//            }
//        }
//        if (upperFreq[i] % 2 == 0)
//        {
//            sum += upperFreq[i];
//        }
//        else
//        {
//            if (upperFreq[i] > 1)
//                sum += upperFreq[i] - 1;
//
//            if (!single)
//            {
//                ++sum;
//                single = true;
//            }
//        }
//    }
//    return sum;
//}

# if 0
int main()
{
    // Provided test cases
    assert(longestPalindrome("abccccdd") == 7);

    assert(longestPalindrome("a") == 1);

    std::cout << "Success!\n";

	return 0;
}
#endif