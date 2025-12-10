#include <iostream>
#include <cassert>
#include <climits>

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;

    unsigned int result{ 0 };
    int sign{ (dividend > 0) ^ (divisor > 0) ? -1 : 1 };
    auto unsigned_abs{ [](int num)
        {return num == INT_MIN ? static_cast<unsigned int>(INT_MAX) + 1 : static_cast<unsigned int>(abs(num)); } };
    unsigned int dend{ unsigned_abs(dividend) };
    unsigned int sor{ unsigned_abs(divisor) };

    while (dend >= sor)
    {
        unsigned int count{ 0 };
        while (dend > (sor << (count + 1)))
        {
            ++count;
        }
        dend -= sor << count;
        result += 1 << count;
    }
    if (result == (1 << 31) && sign == 1)
        return INT_MAX;

    return sign > 0 ? result : 0 - result;
}

#if 0
int main()
{
    // Provided test cases
    assert(divide(10, 3) == 3);

    assert(divide(7, -3) == -2);

    std::cout << "Success!\n";

    return 0;
}
#endif