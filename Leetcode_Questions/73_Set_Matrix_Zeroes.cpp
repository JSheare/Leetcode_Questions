#include <iostream>
#include <cassert>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix)
{
    int col0{ 1 };
    for (int i{ 0 }; i < matrix.size(); ++i)
    {
        if (matrix[i][0] == 0)
            col0 = 0;

        for (int j{ 1 }; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i{ static_cast<int>(matrix.size()) - 1 }; i >= 0; --i)
    {
        for (int j{ static_cast<int>(matrix[0].size()) - 1 }; j >= 1; --j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1} };
    std::vector<std::vector<int>> correct1{
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1} };
    setZeroes(test1);
    assert(test1 == correct1);

    std::vector<std::vector<int>> test2{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5} };
    std::vector<std::vector<int>> correct2{
        {0, 0, 0, 0},
        {0, 4, 5, 0},
        {0, 3, 1, 0} };
    setZeroes(test2);
    assert(test2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif
