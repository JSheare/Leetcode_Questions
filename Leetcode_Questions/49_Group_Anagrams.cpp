#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (auto& word : strs)
    {
        std::string key{ word };
        std::sort(key.begin(), key.end());
        mp[key].push_back(word);
    }

    std::vector<std::vector<std::string>> groups;
    for (auto& pair : mp)
    {
        groups.push_back(pair.second);
    }
    return groups;
}

# if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "eat", "tea", "tan", "ate", "nat", "bat" };
    std::vector<std::vector<std::string>> correct1{ {"eat", "tea", "ate"} , {"tan", "nat"}, {"bat"} };
    assert(groupAnagrams(test1) == correct1);

    std::vector<std::string> test2{ "" };
    std::vector<std::vector<std::string>> correct2{ {""} };
    assert(groupAnagrams(test2) == correct2);

    std::vector<std::string> test3{ "a" };
    std::vector<std::vector<std::string>> correct3{ {"a"} };
    assert(groupAnagrams(test3) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif