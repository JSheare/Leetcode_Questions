#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

bool isScrambleHelper(std::unordered_map<std::string, bool>& cache, std::string& s1, std::string& s2)
{
    if (s1 == s2)
        return true;

    if (cache.contains(s1 + s2))
        return cache[s1 + s2];

    // Initializing character frequency vectors
    std::vector<int> a(26, 0);
    std::vector<int> b(26, 0);
    std::vector<int> c(26, 0);

    for (int i{ 1 }; i < s1.size(); ++i)
    {
        int j{ static_cast<int>(s1.size()) - i };
        // Updating character frequency vectors
        ++a[s1[i - 1] - 'a'];
        ++b[s2[i - 1] - 'a'];
        ++c[s2[j] - 'a'];

        std::string s1Left{ s1.substr(0, i) };
        std::string s1Right{ s1.substr(i, j) };

        // Checking no swap
        std::string s2Left{ s2.substr(0, i) };
        std::string s2Right{ s2.substr(i, j) };
        if (a == b && isScrambleHelper(cache, s1Left, s2Left) && isScrambleHelper(cache, s1Right, s2Right))
        {
            cache[s1 + s2] = true;
            return true;
        }
        // Checking swap
        s2Left = s2.substr(j, i);
        s2Right = s2.substr(0, j);
        if (a == c && isScrambleHelper(cache, s1Left, s2Left) && isScrambleHelper(cache, s1Right, s2Right))
        {
            cache[s1 + s2] = true;
            return true;
        }
    }
    cache[s1 + s2] = false;
    return false;
}

bool isScramble(std::string s1, std::string s2)
{
    std::unordered_map<std::string, bool> cache;
    return isScrambleHelper(cache, s1, s2);
}

#if 0
int main()
{
    // Provided test cases
    assert(isScramble("great", "rgeat") == true);

    assert(isScramble("abcde", "caebd") == false);

    assert(isScramble("a", "a") == true);

    std::cout << "Success!\n";

    return 0;
}
#endif
