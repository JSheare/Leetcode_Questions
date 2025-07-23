#include <iostream>
#include <cassert>
#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList)
{
    std::unordered_set<std::string> words(wordList.begin(), wordList.end());
    std::queue<std::string> q;
    q.push(beginWord);
    int distance{ 1 };
    while (!q.empty())
    {
        int n{ static_cast<int>(q.size()) };
        while (n)
        {
            std::string word{ q.front() };
            q.pop();
            if (word == endWord)
                return distance;

            for (int i{ 0 }; i < word.size(); ++i)
            {
                char c = word[i];
                for (int j{ 0 }; j < 26; ++j)
                {
                    word[i] = 'a' + j;
                    if (words.contains(word))
                    {
                        q.push(word);
                        words.erase(word);
                    }
                }
                word[i] = c;
            }
            --n;
        }
        ++distance;
    }
    return 0;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "hot", "dot", "lot", "log", "cog" };
    assert(ladderLength("hit", "cog", test1) == 5);

    std::vector<std::string> test2{ "hot", "dot", "lot", "log" };
    assert(ladderLength("hit", "cog", test2) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif