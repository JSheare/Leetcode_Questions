#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

bool isPalindrome(std::string& str, int left, int right)
{
    while (left < right)
    {
        if (str[left++] != str[right--])
            return false;
    }
    return true;
}

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words)
{
    // There are two ways that two words word1 and word2 can make a valid palindrome pair:
    // word1 + word2 where word1 = reverse(word2)
    // word1 + (isPalindrome(word2, 0, i) = true) + word2[i:] where word1 = reverse(word2[i:])
    std::vector<std::vector<int>> pairs;
    std::set<int> st;
    std::unordered_map<std::string, int> map;
    for (int i{ 0 }; i < words.size(); ++i)
    {
        map[words[i]] = i;
        st.insert(static_cast<int>(words[i].size()));
    }
    for (int i{ 0 }; i < words.size(); ++i)
    {
        std::string word = words[i];
        int len{ static_cast<int>(word.size()) };
        std::reverse(word.begin(), word.end());
        // Recording pairs conforming to the first definition
        if (map.contains(word) && map[word] != i)
        {
            pairs.push_back({ i, map[word] });
        }
        // Recording pairs conforming to the second definition
        auto a{ st.find(len) };
        for (auto it{ st.begin() }; it != a; ++it)
        {
            int j{ *it };
            if (isPalindrome(word, 0, len - 1 - j) && map.count(word.substr(len - j)))
            {
                pairs.push_back({ i, map[word.substr(len - j)] });
            }
            if (isPalindrome(word, j, len - 1) && map.count(word.substr(0, j)))
            {
                pairs.push_back({ map[word.substr(0, j)], i });
            }
        }
    }
    return pairs;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> words1{ "abcd", "dcba", "lls", "s", "sssll" };
    std::vector<std::vector<int>> pairs1{ {0, 1}, {1, 0}, {3, 2}, {2, 4} };
    assert(palindromePairs(words1) == pairs1);

    std::vector<std::string> words2{ "bat", "tab", "cat" };
    std::vector<std::vector<int>> pairs2{ {0, 1}, {1, 0} };
    assert(palindromePairs(words2) == pairs2);

    std::vector<std::string> words3{ "a", "" };
    std::vector<std::vector<int>> pairs3{ {0, 1}, {1, 0} };
    assert(palindromePairs(words3) == pairs3);

    std::cout << "Success!\n";

    return 0;
}
#endif