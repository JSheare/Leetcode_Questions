#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges)
{
    if (n == 1)
        return { 0 };

    // Building the graph out as an adjacency list
    std::vector<int> degree(n, 0);
    std::vector<std::vector<int>> graph(n);
    for (auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        ++degree[edge[0]];
        ++degree[edge[1]];
    }

    // Setting up initial leaves to prune
    std::queue<int> q;
    for (int i{ 0 }; i < n; ++i)
    {
        if (degree[i] == 1)
            q.push(i);
    }

    // Iteratevly pruning leaves until we reach the root(s)
    int numNodes{ n };
    while (numNodes > 2)
    {
        int numLeaves{ static_cast<int>(q.size()) };
        numNodes -= numLeaves;
        for (int i{ 0 }; i < numLeaves; ++i)
        {
            int leaf{ q.front() };
            q.pop();
            for (int neighbor : graph[leaf])
            {
                if (--degree[neighbor] == 1)
                    q.push(neighbor);
            }
        }

    }
    std::vector<int> minHeightTrees;
    while (!q.empty())
    {
        minHeightTrees.push_back(q.front());
        q.pop();
    }
    return minHeightTrees;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 0}, {1, 2}, {1, 3} };
    std::vector<int> correct1{ 1 };
    assert(findMinHeightTrees(4, test1) == correct1);

    std::vector<std::vector<int>> test2{ {3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4} };
    std::vector<int> correct2{ 3, 4 };
    assert(findMinHeightTrees(6, test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif