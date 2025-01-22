#include <iostream>
#include <cassert>
#include <string>

int romanVal(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }
    return 0;
}

int romanToInt(std::string s)
{
    int ans{ 0 };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        if (romanVal(s[i]) < romanVal(s[i + 1]))
            ans -= romanVal(s[i]);
        else
            ans += romanVal(s[i]);
    }
    return ans;
}

#if 0
int main()
{
    // Provided test cases
    assert(romanToInt("III") == 3);

    assert(romanToInt("LVIII") == 58);

    assert(romanToInt("MCMXCIV") == 1994);

    std::cout << "Success!\n";

    return 0;
}
#endif
