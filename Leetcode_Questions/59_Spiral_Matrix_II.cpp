#include <iostream>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n)
{
    int left{ 0 };
    int right{ n - 1 };
    int top{ 0 };
    int bottom{ n - 1 };
    int num{ 1 };
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    while (left <= right && top <= bottom)
    {
        for (int i{ left }; i <= right; ++i)
        {
            matrix[top][i] = num++;
        }
        ++top;

        for (int i{ top }; i <= bottom; ++i)
        {
            matrix[i][right] = num++;
        }
        --right;

        if (!(left <= right && top <= bottom))
            break;

        for (int i{ right }; i >= left; --i)
        {
            matrix[bottom][i] = num++;
        }
        --bottom;

        for (int i{ bottom }; i >= top; --i)
        {
            matrix[i][left] = num++;
        }
        ++left;
    }
    return matrix;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5} };
    assert(generateMatrix(3) == test1);

    std::vector<std::vector<int>> test2{ {1} };
    assert(generateMatrix(1) == test2);

    std::cout << "Success!\n";

    return 0;
}
#endif