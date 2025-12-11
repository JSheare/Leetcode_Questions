#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    int length{ static_cast<int>(words[0].size()) };
    std::unordered_map<std::string, int> mp;
    std::unordered_map<std::string, int> seen;
    std::vector<int> indices;
    // Setting up the word mapping
    for (auto& word : words)
    {
        ++mp[word];
    }
    // Moving a sliding window across the string starting from all possible offsets
    for (int offset{ 0 }; offset < length; ++offset)
    {
        int size{ 0 };
        // Window increases/decreases in increments of length
        for (int i{ offset }; i + length <= s.size(); i += length)
        {
            std::string sub{ s.substr(i, length) };
            if (!mp.contains(sub))
            {
                seen.clear();
                size = 0;
                continue;
            }
            ++seen[sub];
            ++size;
            // Shrinking the window so that it doesn't go over any of the max word counts
            while (seen[sub] > mp[sub])
            {
                std::string first{ s.substr(i - (size - 1) * length, length) };
                --seen[first];
                --size;
            }
            if (size == words.size())
                indices.push_back(i - (size - 1) * length);
        }
        seen.clear();
    }
    return indices;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "foo", "bar" };
    std::vector<int> answer1{ 0, 9 };
    assert(findSubstring("barfoothefoobarman", test1) == answer1);

    std::vector<std::string> test2{ "word", "good", "best", "word" };
    std::vector<int> answer2{};
    assert(findSubstring("wordgoodgoodgoodbestword", test2) == answer2);

    std::vector<std::string> test3{ "bar", "foo", "the" };
    std::vector<int> answer3{ 6, 9, 12 };
    assert(findSubstring("barfoofoobarthefoobarman", test3) == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif