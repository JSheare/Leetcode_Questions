#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void nQueensIIHelper(std::vector<std::string>& board, std::vector<char>& columns, int& count, int row)
{
    if (row < 0)
    {
        ++count;
        return;
    }
    int diff{ 1 };
    bool invalid{ false };
    for (int i{ 0 }; i < board.size(); ++i)
    {
        if (!columns[i])
        {
            diff = 1;
            invalid = false;
            while (row + diff < board.size())
            {
                if (i - diff >= 0 && board[row + diff][i - diff] == 'Q')
                {
                    invalid = true;
                    break;
                }
                if (i + diff < board.size() && board[row + diff][i + diff] == 'Q')
                {
                    invalid = true;
                    break;
                }
                ++diff;
            }
            if (invalid)
                continue;

            board[row][i] = 'Q';
            columns[i] = 1;
            nQueensIIHelper(board, columns, count, row - 1);
            board[row][i] = '.';
            columns[i] = 0;
        }
    }
}

int totalNQueens(int n)
{
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<char> columns(n, 0);
    int count{ 0 };
    nQueensIIHelper(board, columns, count, n - 1);
    return count;
}

#if 0
int main()
{
    // Provided test cases
    assert(totalNQueens(4) == 2);

    assert(totalNQueens(1) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif