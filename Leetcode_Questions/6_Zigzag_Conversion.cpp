#include <iostream>
#include <cassert>
#include <string>

std::string convert(std::string s, int numRows)
{
    if (numRows == 1)
        return s;

    std::string result(s.size(), '-');
    int maxIndex{ static_cast<int>(s.size()) - 1 };
    int currentRow{ 0 };
    int currentIter{ 0 };
    int maxOffset{ numRows * 2 - 2 };
    int offset{ 0 };
    int index{ 0 };
    bool flip{ false };
    for (int i{ 0 }; i < s.size(); ++i)
    {
        if (currentIter == 0)
            index = currentRow;
        else
        {
            if (!flip)
                offset = maxOffset - (currentRow * 2);
            else
                offset = maxOffset - offset;

            if (offset == 0)  // Rows with no zag
                offset = maxOffset;

            index += offset;
            flip = !flip;
        }
        if (index > maxIndex)
        {
            flip = false;
            ++currentRow;
            currentIter = 0;
            offset -= 2;
            index = currentRow;
        }
        result[i] = s[index];
        ++currentIter;
    }
    return result;
}

#if 0
int main()
{
    // Provided test cases
    assert(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");

    assert(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");

    assert(convert("A", 1) == "A");

    std::cout << "Success!\n";

    return 0;
}
#endif