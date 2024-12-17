#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<std::vector<int>> adjacency(numCourses);  // Courses that a course is a prereq for (outgoing edges)
    std::vector<int> indegree(numCourses, 0);  // Num of prereqs a course has (num of incoming edges)
    int numSatisfied{ 0 };

    // Setting up the graph
    for (std::vector<int>& pair : prerequisites)
    {
        adjacency[pair[1]].push_back(pair[0]);
        ++indegree[pair[0]];
    }
    // Doing a BFS starting from nodes with no prereqs
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
        ++numSatisfied;
        for (int nextCourse : adjacency[currentCourse])
        {
            --indegree[nextCourse];  // One more prereq satisfied
            if (!indegree[nextCourse])  // All prereqs satisfied
                q.push(nextCourse);
        }
    }
    return numSatisfied == numCourses;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 0} };
    assert(canFinish(2, test1));

    std::vector<std::vector<int>> test2{ {1, 0}, {0, 1} };
    assert(!canFinish(2, test2));

    std::cout << "Success!\n";

    return 0;
}
#endif