#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void nQueensHelper(std::vector<std::vector<std::string>>& solutions, std::vector<std::string>& board, std::vector<int>& columns, int row)
{
    if (row < 0)
    {
        solutions.push_back(board);
        return;
    }

    int diff{ 1 };
    bool invalid{ false };
    for (int i{ 0 }; i < board.size(); ++i)
    {
        if (!columns[i])  // Checking if this column is already occupied
        {
            // Checking if this square is vulnerable on the lower diagonals
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
            nQueensHelper(solutions, board, columns, row - 1);
            board[row][i] = '.';
            columns[i] = 0;
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> solutions;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<int> columns(n, 0);
    nQueensHelper(solutions, board, columns, n - 1);
    return solutions;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<std::string>> answer1{
        {"..Q.",
         "Q...",
         "...Q",
         ".Q.."},

        {".Q..",
         "...Q",
         "Q...",
         "..Q."}
    };
    assert(solveNQueens(4) == answer1);

    std::vector<std::vector<std::string>> answer2{
        {"Q"}
    };
    assert(solveNQueens(1) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif