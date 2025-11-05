#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::string intToRoman(int num)
{
    std::vector<int> values{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    std::vector<std::string> romans{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    std::string numeral;
    for (int i{ 0 }; i < 13; ++i)
    {
        if (num == 0)
            break;

        int count{ num / values[i] };
        while (count)
        {
            numeral += romans[i];
            --count;
        }
        num %= values[i];
    }
    return numeral;
}

#if 0
int main()
{
    // Provided test cases
    assert(intToRoman(3749) == "MMMDCCXLIX");

    assert(intToRoman(58) == "LVIII");

    assert(intToRoman(1994) == "MCMXCIV");

    std::cout << "Success!\n";

    return 0;
}
#endif