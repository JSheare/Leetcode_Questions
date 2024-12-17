#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <utility>

// BFS solution
#if 0
void bfs(std::vector<std::vector<int>>& heights, std::queue<std::pair<int, int>>& q, std::vector<std::vector<int>>& visited, int m, int n)
{
    int dx[4]{ 1, -1, 0, 0 };
    int dy[4]{ 0, 0, 1, -1 };
    while (!q.empty())
    {
        int r{ q.front().first };
        int c{ q.front().second };
        q.pop();
        visited[r][c] = 1;
        if (r > 0 && !visited[r - 1][c] && heights[r - 1][c] >= heights[r][c])
            q.push({ r - 1, c });
        if (r < m - 1 && !visited[r + 1][c] && heights[r + 1][c] >= heights[r][c])
            q.push({ r + 1, c });

        if (c > 0 && !visited[r][c - 1] && heights[r][c - 1] >= heights[r][c])
            q.push({ r, c - 1 });

        if (c < n - 1 && !visited[r][c + 1] && heights[r][c + 1] >= heights[r][c])
            q.push({ r, c + 1 });
    }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
{
    int m{ static_cast<int>(heights.size()) };
    int n{ static_cast<int>(heights[0].size()) };
    std::vector<std::vector<int>> pVisited(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> aVisited(m, std::vector<int>(n, 0));
    std::queue<std::pair<int, int>> q;

    // Pacific bfs
    for (int r{ 0 }; r < m; ++r) { q.push({ r, 0 }); }
    for (int c{ 1 }; c < n; ++c) { q.push({ 0, c }); }
    bfs(heights, q, pVisited, m, n);

    // Atlantic bfs
    int maxRow{ m - 1 };
    int maxColumn{ n - 1 };
    for (int c{ 0 }; c < n; ++c) { q.push({ maxRow, c }); }
    for (int r{ 0 }; r < maxRow; ++r) { q.push({ r, maxColumn }); }
    bfs(heights, q, aVisited, m, n);

    // Checking for common cells
    std::vector<std::vector<int>> cells;
    for (int r{ 0 }; r < m; ++r)
    {
        for (int c{ 0 }; c < n; ++c)
        {
            if (pVisited[r][c] && aVisited[r][c])
                cells.push_back({ r, c });
        }
    }
    return cells;
}
#endif


// DFS solution
#if 1
void dfs(std::vector<std::vector<int>>& heights, std::vector<std::vector<int>>& visited, int r, int c, int m, int n)
{
    visited[r][c] = 1;
    if (r > 0 && !visited[r - 1][c] && heights[r - 1][c] >= heights[r][c])
        dfs(heights, visited, r - 1, c, m, n);
    if (r < m - 1 && !visited[r + 1][c] && heights[r + 1][c] >= heights[r][c])
        dfs(heights, visited, r + 1, c, m, n);

    if (c > 0 && !visited[r][c - 1] && heights[r][c - 1] >= heights[r][c])
        dfs(heights, visited, r, c - 1, m, n);

    if (c < n - 1 && !visited[r][c + 1] && heights[r][c + 1] >= heights[r][c])
        dfs(heights, visited, r, c + 1, m, n);
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights)
{
    int m{ static_cast<int>(heights.size()) };
    int n{ static_cast<int>(heights[0].size()) };
    std::vector<std::vector<int>> pVisited(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> aVisited(m, std::vector<int>(n, 0));

    for (int r{ 0 }; r < m; ++r)
    {
        dfs(heights, pVisited, r, 0, m, n);
        dfs(heights, aVisited, r, n - 1, m, n);
    }
    for (int c{ 0 }; c < n; ++c)
    {
        dfs(heights, pVisited, 0, c, m, n);
        dfs(heights, aVisited, m - 1, c, m, n);
    }

    std::vector<std::vector<int>> cells;
    for (int r{ 0 }; r < m; ++r)
    {
        for (int c{ 0 }; c < n; ++c)
        {
            if (pVisited[r][c] && aVisited[r][c])
                cells.push_back({ r, c });
        }
    }
    return cells;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ 
        {1, 2, 2, 3, 5}, 
        {3, 2, 3, 4, 4}, 
        {2, 4, 5, 3, 1}, 
        {6, 7, 1, 4, 5}, 
        {5, 1, 1, 2, 4} 
    };
    std::vector<std::vector<int>> correct1{ {0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0} };
    assert(pacificAtlantic(test1) == correct1);

    std::vector<std::vector<int>> test2{ {1} };
    std::vector<std::vector<int>> correct2{ {0, 0} };
    assert(pacificAtlantic(test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif
