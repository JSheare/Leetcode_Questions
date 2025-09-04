#include <iostream>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

// Standard graph bfs solution
#if 0
int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target)
{
    std::unordered_map<int, std::vector<int>> stopMap;
    for (int i{ 0 }; i < routes.size(); ++i)
    {
        for (int j : routes[i])
        {
            stopMap[j].push_back(i);
        }
    }
    std::queue<std::pair<int, int>> q;
    q.push({ source, 0 });
    std::unordered_set<int> visited{ source };
    while (!q.empty())
    {
        int stop = q.front().first;
        int busNum = q.front().second;
        q.pop();
        if (stop == target)
            return busNum;

        for (int i : stopMap[stop])
        {
            for (int j : routes[i])
            {
                if (!visited.contains(j))
                {
                    visited.insert(j);
                    q.push({ j, busNum + 1 });
                }
            }
            routes[i].clear();
        }
    }
    return -1;
}
#endif

// Modified Bellman-Ford algorithm solution
#if 1
int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target)
{
    if (source == target)
        return 0;

    int numRoutes{ static_cast<int>(routes.size()) };
    int maxStops{ std::max(source, target) };  // max with source and target in case they aren't on any of the routes
    for (auto& route : routes)
    {
        for (auto& stop : route)
        {
            maxStops = std::max(maxStops, stop);
        }
    }
    std::vector<int> countVector(maxStops + 1, numRoutes + 1);  // Records the minimum number of buses to reach each stop
    countVector[source] = 0;  // No busses needed to reach the source
    bool flag{ true };
    while (flag)
    {
        flag = false;
        for (auto& route : routes)
        {
            // Finding the minimum number of busses to get to the current route
            int minBuses{ numRoutes + 1 };
            for (auto stop : route)
            {
                minBuses = std::min(minBuses, countVector[stop]);
            }
            // minBuses is like the entry cost of getting on this route. Therefore, the cost to reach any stop
            // on the route is minBuses (entry) + 1 (this route's bus). We update every stop on the route
            // accordingly
            for (auto stop : route)
            {
                if (minBuses + 1 < countVector[stop])
                {
                    // The flag indicates that we've made some kind of improvement on this iteration. If we 
                    // progress through an entire iteration without making any improvements, then we've relaxed
                    // our assumed solutions (countVector) as much as possible and have therefore reached THE solution
                    flag = true;
                    countVector[stop] = minBuses + 1;
                }
            }
        }
    }
    return countVector[target] == numRoutes + 1 ? -1 : countVector[target];
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> routes1{ {1, 2, 7}, {3, 6, 7} };
    assert(numBusesToDestination(routes1, 1, 6) == 2);

    std::vector<std::vector<int>> routes2{ {7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13} };
    assert(numBusesToDestination(routes2, 15, 12) == -1);

    std::cout << "Success!\n";

    return 0;
}
#endif