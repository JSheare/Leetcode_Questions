#include <iostream>
#include <cassert>
#include <cctype>
#include <string>

bool isNumber(std::string s)
{
    bool hasDigit{ false };
    bool hasDecimal{ false };
    bool hasExponent{ false };
    for (int i{ 0 }; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
            hasDigit = true;
        else if (s[i] == '.')
        {
            if (hasDecimal || hasExponent)
                return false;

            hasDecimal = true;
        }
        else if ((s[i] == 'e' || s[i] == 'E') && !hasExponent)
        {
            if (hasExponent || !hasDigit)
                return false;

            hasExponent = true;
            hasDigit = false;
        }
        else if ((s[i] == '+' || s[i] == '-'))
        {
            if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E'))
                return false;
        }
        else
            return false;
    }
    return hasDigit;
}

#if 0
int main()
{
    // Provided test cases
    assert(isNumber("0") == true);
    
    assert(isNumber("e") == false);

    assert(isNumber(".") == false);

    std::cout << "Success!\n";

    return 0;
}
#endif