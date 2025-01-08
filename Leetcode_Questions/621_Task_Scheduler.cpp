#include <iostream>
#include <cassert>
#include <queue>
#include <vector>
#include <algorithm>

// Map/priority queue solution
#if 0
int leastInterval(std::vector<char>& tasks, int n)
{
    std::priority_queue<int> pq;
    std::vector<int> mp(26, 0);
    for (auto& task : tasks)
    {
        ++mp[task - 'A'];
    }
    for (int taskFreq{ 0 }; taskFreq < mp.size(); ++taskFreq)
    {
        if (mp[taskFreq])
            pq.push(mp[taskFreq]);
    }
    int time{ 0 };
    while (!pq.empty())
    {
        std::vector<int> remaining;
        int cycle{ n + 1 };  // 1 for the first task, n for the cooldown
        while (cycle && !pq.empty())
        {
            int maxFreq{ pq.top() };
            pq.pop();
            if (maxFreq > 1)
                remaining.push_back(maxFreq - 1);

            ++time;
            --cycle;
        }
        for (auto& count : remaining)
            pq.push(count);

        if (pq.empty())
            break;

        time += cycle;  // Adding the idle time
    }
    return time;
}
#endif

// Formula solution
#if 1
int leastInterval(std::vector<char>& tasks, int n)
{
    std::vector<int> mp(26, 0);
    int maxFreq{ 0 };
    int maxFreqCount{ 0 };
    for (auto& task : tasks)
    {
        maxFreq = std::max(maxFreq, ++mp[task - 'A']);
    }
    for (int i{ 0 }; i < 26; ++i)
    {
        if (mp[i] == maxFreq)
            ++maxFreqCount;
    }
    // Since we have to wait through a cooldown of n (frequency of n + 1), there will always be 
    // at least maxFreq - 1 full cycles plus however many max frequency tasks are left over afterwards, i.e.
    int time{ (n + 1) * (maxFreq - 1) + maxFreqCount };
    // In case there are also some non-maxFreq tasks left over for the very last cycle (tasks.size() > time),
    // we return the max of the two
    return std::max(time, static_cast<int>(tasks.size()));
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<char> test1{ 'A', 'A', 'A', 'B', 'B', 'B' };
    assert(leastInterval(test1, 2) == 8);

    std::vector<char> test2{ 'A', 'C', 'A', 'B', 'D', 'B' };
    assert(leastInterval(test2, 1) == 6);

    std::vector<char> test3{ 'A', 'A', 'A', 'B', 'B', 'B' };
    assert(leastInterval(test3, 3) == 10);

    std::cout << "Success!\n";

    return 0;
}
#endif