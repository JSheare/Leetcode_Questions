#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix)
{
    // Transposing the matrix
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        for (int j{ 0 }; j < matrix[0].size(); ++j)
        {
            if (i == j)
                break;

            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reversing the rows of the matrix
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} };
    std::vector <std::vector<int>> correct1{
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3} };
    rotate(test1);
    assert(test1 == correct1);

    std::vector<std::vector<int>> test2{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16} };
    std::vector<std::vector<int>> correct2{
        {15, 13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7, 10, 11} };
    rotate(test2);
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif