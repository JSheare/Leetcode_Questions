#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>

int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
    // Note:
    // In the leetcode IDE I actually use an array of vectors of pairs for the graph
    // but the visual studio compiler doesn't support non-const array declaration by default, so here I'm just using a vector instead
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (auto& flight : flights)
    {
        graph[flight[0]].push_back({ flight[1], flight[2] });
    }
    std::vector<int> cost(n, INT_MAX);
    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({ src, {0, 0} });
    while (!q.empty())
    {
        int node{ q.front().first };
        int nodeCost{ q.front().second.first };
        int stops{ q.front().second.second };
        q.pop();
        if (stops > k)
            continue;

        for (auto& [child, childCost] : graph[node])
        {
            int newCost{ nodeCost + childCost };
            if (newCost < cost[child])
            {
                cost[child] = newCost;
                q.push({ child, {newCost, stops + 1} });
            }
        }
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200} };
    assert(findCheapestPrice(4, test1, 0, 3, 1) == 700);

    std::vector<std::vector<int>> test2{ {0, 1, 100}, {1, 2, 100}, {0, 2, 500} };
    assert(findCheapestPrice(3, test2, 0, 2, 1) == 200);

    std::vector<std::vector<int>> test3{ {0, 1, 100}, {1, 2, 100}, {0, 2, 500} };
    assert(findCheapestPrice(3, test3, 0, 2, 0) == 500);

    std::cout << "Success!\n";

    return 0;
}
#endif