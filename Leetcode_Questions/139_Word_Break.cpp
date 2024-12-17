#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
    std::vector<bool> cache(s.size() + 1, false);  // Memoization for partition points
    cache[0] = true;
    std::unordered_set<std::string> words;
    int maxLen{ 0 };
    for (auto& word : wordDict)
    {
        words.insert(word);
        maxLen = std::max(maxLen, static_cast<int>(word.size()));
    }
    for (int i{ 1 }; i <= s.size(); ++i)
    {
        for (int j{ 0 }; j < i; ++j)
        {
            if (i - j > maxLen)  // To prevent checking partitions that aren't going to work
                continue;

            if (cache[j] && words.count(s.substr(j, i - j)))
            {
                cache[i] = true;
                break;
            }
        }
    }
    return cache[s.size()];
}

#if 0
int main()
{
    // Provided test cases
    std::string test1{ "leetcode" };
    std::vector<std::string> words1{ "leet", "code" };
    assert(wordBreak(test1, words1) == true);

    std::string test2{ "applepenapple" };
    std::vector<std::string> words2{ "apple", "pen" };
    assert(wordBreak(test2, words2) == true);

    std::string test3{ "catsandog" };
    std::vector<std::string> words3{ "cats", "dog", "sand", "and", "cat" };
    assert(wordBreak(test3, words3) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif