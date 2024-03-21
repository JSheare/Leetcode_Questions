#include <iostream>
#include <assert.h>
#include <utility>
#include <vector>
#include <queue>

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
{
    int m{ static_cast<int>(mat.size()) };
    int n{ static_cast<int>(mat[0].size()) };
    int maxDist{ n * m };
    std::queue<std::pair<int, int>> q;
    // Add cells with 0 value to queue for BFS and set everything else to the max possible dist
    for (int i{ 0 }; i < m; ++i)
    {
        for (int j{ 0 }; j < n; ++j)
        {
            if (mat[i][j] == 0)
                q.push(std::make_pair(i, j));
            else
                mat[i][j] = maxDist;
        }
    }
    std::vector<std::pair<int, int>> directions{
        std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1) };
    // Do a BFS and update each non-zero cell as we find smaller distances
    while (!q.empty())
    {
        std::pair<int, int> cell{ q.front() };
        q.pop();
        for (std::pair<int, int> direction : directions)
        {
            int r{ cell.first + direction.first };
            int c{ cell.second + direction.second };
            if (0 <= r && r < m && 0 <= c && c < n && mat[r][c] > mat[cell.first][cell.second] + 1)
            {
                q.push(std::make_pair(r, c));
                mat[r][c] = mat[cell.first][cell.second] + 1;
            }
        }
    }
    return mat;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    std::vector<std::vector<int>> correct1{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    updateMatrix(test1);
    assert(test1 == correct1);

    std::vector<std::vector<int>> test2{ {0, 0, 0}, {0, 1, 0}, {1, 1, 1} };
    std::vector<std::vector<int>> correct2{ {0, 0, 0}, {0, 1, 0}, {1, 2, 1} };
    updateMatrix(test2);
    assert(test2 == correct2);

    std::cout << "Success!\n";

	return 0;
}
#endif