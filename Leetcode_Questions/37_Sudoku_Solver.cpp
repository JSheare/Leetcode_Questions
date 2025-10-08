#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

#include "SudokuMask.h"

// Brute force recursive backtrack solution
#if 0
bool isValidSudokuCell(std::vector<std::vector<char>>& board, int row, int col, char c)
{
    for (int i{ 0 }; i < 9; ++i)
    {
        if (board[row][i] == c)
            return false;
        if (board[i][col] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool sudokuBacktrack(std::vector<std::vector<char>>& board) 
{
    for (int i{ 0 }; i < 9; ++i)
    {
        for (int j{ 0 }; j < 9; ++j)
        {
            if (board[i][j] == '.')
            {
                for (char c{ '1' }; c <= '9'; ++c)
                {
                    if (isValidSudokuCell(board, i, j, c)) {
                        board[i][j] = c;
                        if (sudokuBacktrack(board))
                            return true;

                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(std::vector<std::vector<char>>& board)
{
    sudokuBacktrack(board);
}
#endif

// Bit mask recursive backtrack solution
#if 1
// See SudokuMask.h and SudokuMask.cpp for full implementation of the bit mask

bool sudokuBacktrack(std::vector<std::vector<char>>& board, SudokuMask& mask, std::vector<std::pair<int, int>>& cells, int level)
{
    if (level == cells.size())
        return true;

    int bestCount{ 10 };
    int bestIndex{ level };
    for (int i{ level }; i < cells.size(); ++i)
    {
        int count{ mask.numPossibilities(cells[i].first, cells[i].second) };
        if (count < bestCount)
        {
            bestCount = count;
            bestIndex = i;
        }
    }
    if (bestCount == 0)
        return false;

    swap(cells[level], cells[bestIndex]);
    int i{ cells[level].first };
    int j{ cells[level].second };
    for (auto& p : mask.getPossibilities(i, j))
    {
        board[i][j] = p + '0';
        mask.mark(i, j, p);
        if (sudokuBacktrack(board, mask, cells, level + 1))
            return true;

        mask.unmark(i, j, p);
    }
    board[i][j] = '.';
    return false;
}

void solveSudoku(std::vector<std::vector<char>>& board)
{
    SudokuMask mask;
    std::vector<std::pair<int, int>> cells;
    for (int i{ 0 }; i < 9; ++i)
    {
        for (int j{ 0 }; j < 9; ++j)
        {
            if (board[i][j] == '.')
                cells.push_back({ i, j });
            else
                mask.mark(i, j, board[i][j] - '0');
        }
    }
    sudokuBacktrack(board, mask, cells, 0);
}
#endif

#if 0
int main()
{
    // Provided test case
    std::vector<std::vector<char>> board1{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'} };
    std::vector<std::vector<char>> answer1{
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'} };
    solveSudoku(board1);
    assert(board1 == answer1);

    std::cout << "Success!\n";

    return 0;
}
#endif