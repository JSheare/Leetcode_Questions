#include <vector>
#include <bit>

#include "SudokuMask.h"

SudokuMask::SudokuMask()
{}

void SudokuMask::mark(int i, int j, int val)
{
    int bit{ 1 << (val - 1) };
    row[i] |= bit;
    column[j] |= bit;
    box[(i / 3) * 3 + j / 3] |= bit;
}

void SudokuMask::unmark(int i, int j, int val)
{
    int bit{ 1 << (val - 1) };
    bit = ~bit;
    row[i] &= bit;
    column[j] &= bit;
    box[(i / 3) * 3 + j / 3] &= bit;
}

int SudokuMask::numPossibilities(int i, int j)
{
    // 0x1FF is 0b00000000000000000000000111111111. The purpose of &ing with it is to unset the unused leading bits
    // that get incidentally set by the ~ operation
    //return __builtin_popcount((~(row[i] | column[j] | box[(i / 3) * 3 + j / 3])) & 0x1FF) + 1;  // GCC only
    return std::popcount(static_cast<unsigned>((~(row[i] | column[j] | box[(i / 3) * 3 + j / 3])) & 0x1FF)) + 1;
}

std::vector<int> SudokuMask::getPossibilities(int i, int j)
{
    int mask{ (~(row[i] | column[j] | box[(i / 3) * 3 + j / 3])) & 0x1FF };
    std::vector<int> possibilities;
    while (mask)
    {
        int bit{ mask & -mask };
        mask -= bit;
        // possibilities.push_back(__builtin_ctz(bit) + 1);  // GCC ONLY
        possibilities.push_back(std::countr_zero(static_cast<unsigned>(bit)) + 1);
    }
    return possibilities;
}