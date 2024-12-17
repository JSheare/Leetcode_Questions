#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
{
    std::unordered_map<std::string, int> freq;
    for (auto& word : words)
    {
        ++freq[word];
    }
    auto comp
    {
        [](std::pair<std::string, int>& a, std::pair<std::string, int>& b)
        {return (a.second > b.second) || ((a.second == b.second) && (a.first < b.first)); }
    };
    std::vector<std::pair<std::string, int>> ordered;
    for (auto& it : freq)
    {
        ordered.push_back(it);
    }
    std::sort(ordered.begin(), ordered.end(), comp);
    std::vector<std::string> topK;
    for (int i{ 0 }; i < k; ++i)
    {
        topK.push_back(ordered[i].first);
    }
    return topK;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "i", "love", "leetcode", "i", "love", "coding" };
    std::vector<std::string> correct1{ "i", "love" };
    assert(topKFrequent(test1, 2) == correct1);

    std::vector<std::string> test2{ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    std::vector<std::string> correct2{ "the", "is", "sunny", "day" };
    assert(topKFrequent(test2, 4) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif