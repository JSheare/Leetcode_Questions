#include <iostream>
#include <assert.h>

int reverse(int x)
{
    int reversed{ 0 };
    while (x != 0)
    {
        int digit{ x % 10 };
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10)
            return 0;

        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return reversed;
}

#if 0
int main()
{
    // Provided test cases
    assert(reverse(123) == 321);

    assert(reverse(-123) == -321);

    assert(reverse(120) == 21);

    std::cout << "Success!\n";

    return 0;
}
#endif