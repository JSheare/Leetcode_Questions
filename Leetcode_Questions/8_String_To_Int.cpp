#include <iostream>
#include <assert.h>
#include <string>

int myAtoi(std::string s)
{
    int i{ 0 };
    bool sign{ true };
    long result{ 0 };
    while (i < s.length() && s[i] == ' ')
    {
        ++i;
    }
    if (s[i] == '-')
    {
        sign = false;
        ++i;
    }
    else if (s[i] == '+')
        ++i;

    while (i < s.length())
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            if (result > INT_MAX && sign)
                return INT_MAX;
            else if (result > INT_MAX && !sign)
                return INT_MIN;

            ++i;
        }
        else
            return sign ? result : result * -1;
    }
    return sign ? result : result * -1;
}

#if 0
int main()
{
    // Provided test cases
    assert(myAtoi("42") == 42);

    assert(myAtoi("   -042") == -42);

    assert(myAtoi("1337c0d3") == 1337);

    assert(myAtoi("0-1") == 0);

    assert(myAtoi("words and 987") == 0);

    std::cout << "Success!\n";

	return 0;
}
#endif