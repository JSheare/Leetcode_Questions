#include <iostream>
#include <cassert>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
    bool rows[9][9]{ {false} };
    bool columns[9][9]{ {false} };
    bool boxes[9][9]{ {false} };
    for (int i{ 0 }; i < 9; ++i)
    {
        for (int j{ 0 }; j < 9; ++j)
        {
            if (board[i][j] == '.')
                continue;

            char val{ board[i][j] };
            int boxIdx{ (i / 3) * 3 + (j / 3) };
            if (rows[i][val - '1'] || columns[j][val - '1'] || boxes[boxIdx][val - '1'])
            {
                std::cout << '\n';
                return false;
            }

            rows[i][val - '1'] = true;
            columns[j][val - '1'] = true;
            boxes[boxIdx][val - '1'] = true;
        }
    }
    return true;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> test1{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    assert(isValidSudoku(test1) == true);

    std::vector<std::vector<char>> test2{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
    assert(isValidSudoku(test2) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif