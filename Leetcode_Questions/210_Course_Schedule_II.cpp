#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<std::vector<int>> adjacency(numCourses);
    std::vector<int> indegree(numCourses, 0);
    std::vector<int> order;

    for (auto& pair : prerequisites)
    {
        adjacency[pair[1]].push_back(pair[0]);
        ++indegree[pair[0]];
    }
    std::queue<int> q;
    for (int i{ 0 }; i < numCourses; ++i)
    {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int currentCourse{ q.front() };
        q.pop();
        order.push_back(currentCourse);
        for (int nextCourse : adjacency[currentCourse])
        {
            --indegree[nextCourse];
            if (!indegree[nextCourse])
                q.push(nextCourse);
        }
    }
    if (order.size() != numCourses)
        return {};

    return order;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 0} };
    std::vector<int> correct1{ 0, 1 };
    assert(findOrder(2, test1) == correct1);

    std::vector<std::vector<int>> test2{ {1, 0}, {2, 0}, {3, 1}, {3, 2} };
    std::vector<int> correct2{ 0, 1, 2, 3 };
    assert(findOrder(4, test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif