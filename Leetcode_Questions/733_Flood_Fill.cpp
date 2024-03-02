#include <iostream>
#include <assert.h>
#include <vector>
#include <utility>
#include <queue>

// BFS solution
std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{
    if (color != image[sr][sc])
    {
        int fillColor{ image[sr][sc] };
        std::queue<std::pair<int, int>> pixels;
        pixels.push({ sr, sc });
        while (!pixels.empty())
        {
            int r{ pixels.front().first };
            int c{ pixels.front().second };
            pixels.pop();
            if (image[r][c] == fillColor)
            {
                image[r][c] = color;
                if (r - 1 >= 0)
                    pixels.push({ r - 1, c });
                if (r + 1 < image.size())
                    pixels.push({ r + 1, c });
                if (c - 1 >= 0)
                    pixels.push({ r, c - 1 });
                if (c + 1 < image[0].size())
                    pixels.push({ r, c + 1 });
            }
        }
    }
    return image;
}

// DFS solution
void dfs(std::vector<std::vector<int>>& image, int sr, int sc, int targetColor, int fillColor)
{
    if (image[sr][sc] == fillColor)
    {
        image[sr][sc] = targetColor;
        if (sr - 1 >= 0)
            dfs(image, sr - 1, sc, targetColor, fillColor);
        if (sr + 1 < image.size())
            dfs(image, sr + 1, sc, targetColor, fillColor);
        if (sc - 1 >= 0)
            dfs(image, sr, sc - 1, targetColor, fillColor);
        if (sc + 1 < image[0].size())
            dfs(image, sr, sc + 1, targetColor, fillColor);
    }
}

std::vector<std::vector<int>> floodFillDFS(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{
    if (color != image[sr][sc])
        dfs(image, sr, sc, color, image[sr][sc]);
    return image;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    std::vector<std::vector<int>> answer1{ {2, 2, 2}, {2, 2, 0}, {2, 0, 1} };
    assert(floodFill(test1, 1, 1, 2) == answer1);

    std::vector<std::vector<int>> test2{ {0, 0, 0}, {0, 0, 0} };
    std::vector<std::vector<int>> answer2{ {0, 0, 0}, {0, 0, 0} };
    assert(floodFill(test2, 0, 0, 0) == answer2);

    /*std::vector<std::vector<int>> test1{ {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    std::vector<std::vector<int>> answer1{ {2, 2, 2}, {2, 2, 0}, {2, 0, 1} };
    assert(floodFillDFS(test1, 1, 1, 2) == answer1);

    std::vector<std::vector<int>> test2{ {0, 0, 0}, {0, 0, 0} };
    std::vector<std::vector<int>> answer2{ {0, 0, 0}, {0, 0, 0} };
    assert(floodFillDFS(test2, 0, 0, 0) == answer2);*/

    std::cout << "Success!\n";

    return 0;
}
#endif