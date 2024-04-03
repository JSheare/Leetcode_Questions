#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int orangesRotting(std::vector<std::vector<int>>& grid)
{
    std::queue<std::pair<std::pair<int, int>, int>> q;
    std::vector<std::vector<bool>> visited(
        grid.size(), std::vector<bool>(grid[0].size()));
    int freshCount{ 0 };
    for (int i{ 0 }; i < grid.size(); ++i)
    {
        for (int j{ 0 }; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 2)
            {
                q.push({ {i, j}, 0 });
                visited[i][j] = true;
            }
            else if (grid[i][j] == 1)
                ++freshCount;
        }
    }
    int minutes{ 0 };
    int rottenCount{ 0 };
    while (!q.empty())
    {
        int i{ q.front().first.first };
        int j{ q.front().first.second };
        int time{ q.front().second };
        q.pop();
        minutes = std::max(minutes, time);
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)
        {
            q.push({ {i - 1, j}, time + 1 });
            visited[i - 1][j] = true;
            ++rottenCount;
        }
        if (i + 1 < grid.size() && !visited[i + 1][j] && grid[i + 1][j] == 1)
        {
            q.push({ {i + 1, j}, time + 1 });
            visited[i + 1][j] = true;
            ++rottenCount;
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
        {
            q.push({ {i, j - 1}, time + 1 });
            visited[i][j - 1] = true;
            ++rottenCount;
        }
        if (j + 1 < grid[0].size() && !visited[i][j + 1] && grid[i][j + 1] == 1)
        {
            q.push({ {i, j + 1}, time + 1 });
            visited[i][j + 1] = true;
            ++rottenCount;
        }
    }
    return freshCount == rottenCount ? minutes : -1;
}


// A more memory-efficient version (testing says that it's a little slower but I'm not so sure). Keeping it as an alt just in case
//int orangesRotting(std::vector<std::vector<int>>& grid)
//{
//    std::queue<std::pair<std::pair<int, int>, int>> q;
//    int freshCount{ 0 };
//    for (int i{ 0 }; i < grid.size(); ++i)
//    {
//        for (int j{ 0 }; j < grid[0].size(); ++j)
//        {
//            if (grid[i][j] == 2)
//                q.push({ {i, j}, 0 });
//            else if (grid[i][j] == 1)
//                ++freshCount;
//        }
//    }
//    int minutes{ 0 };
//    int rottenCount{ 0 };
//    while (!q.empty())
//    {
//        int qsize{ static_cast<int>(q.size()) };
//        while (qsize--)
//        {
//            int i{ q.front().first.first };
//            int j{ q.front().first.second };
//            int time{ q.front().second };
//            q.pop();
//            minutes = std::max(minutes, time);
//            if (i - 1 >= 0 && grid[i - 1][j] == 1)
//            {
//                q.push({ {i - 1, j}, time + 1 });
//                grid[i - 1][j] = 2;
//                ++rottenCount;
//            }
//            if (i + 1 < grid.size() && grid[i + 1][j] == 1)
//            {
//                q.push({ {i + 1, j}, time + 1 });
//                grid[i + 1][j] = 2;
//                ++rottenCount;
//            }
//            if (j - 1 >= 0 && grid[i][j - 1] == 1)
//            {
//                q.push({ {i, j - 1}, time + 1 });
//                grid[i][j - 1] = 2;
//                ++rottenCount;
//            }
//            if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
//            {
//                q.push({ {i, j + 1}, time + 1 });
//                grid[i][j + 1] = 2;
//                ++rottenCount;
//            }
//        }
//    }
//    return freshCount == rottenCount ? minutes : -1;
//}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1} };
    assert(orangesRotting(test1) == 4);

    std::vector<std::vector<int>> test2{
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1} };
    assert(orangesRotting(test2) == -1);

    std::vector<std::vector<int>> test3{
        {0, 2} };
    assert(orangesRotting(test3) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif