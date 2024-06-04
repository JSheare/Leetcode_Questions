#include <iostream>
#include <assert.h>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
{
    std::vector<int> answer;
    int top{ 0 };
    int bottom{ static_cast<int>(matrix.size()) - 1 };
    int left{ 0 };
    int right{ static_cast<int>(matrix[0].size()) - 1 };
    while (left <= right && top <= bottom)
    {
        for (int i{ left }; i <= right; ++i)
        {
            answer.push_back(matrix[top][i]);
        }
        ++top;

        for (int i{ top }; i <= bottom; ++i)
        {
            answer.push_back(matrix[i][right]);
        }
        --right;

        if (!(left <= right && top <= bottom))
            break;

        for (int i{ right }; i >= left; --i)
        {
            answer.push_back(matrix[bottom][i]);
        }
        --bottom;

        for (int i{ bottom }; i >= top; --i)
        {
            answer.push_back(matrix[i][left]);
        }
        ++left;
    }
    return answer;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<int> correct1{ 1, 2, 3, 6, 9, 8, 7, 4, 5 };
    assert(spiralOrder(test1) == correct1);

    std::vector<std::vector<int>> test2{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
    std::vector<int> correct2{ 1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7 };
    assert(spiralOrder(test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif