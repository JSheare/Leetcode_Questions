#include <iostream>
#include <cassert>
#include <cstdlib>

/*
Both of the solutions below are based on binary exponentiation, which is defined by the following formula:
          -
        / 1 if n == 0
a^n =  <  (a^(n/2))^2 if n > 0 and n even
        \ (a^((n-1)/2))^2 * a if n > 0 and n odd
          -
In cases where n < 0, you can obviously just flip the sign of n and invert a and the formula will work the same. 
*/

// Recursive solution  (O(log(n)) time complexity, O(log(n)) space complexity)
#if 0
double myPow(double x, int n)
{
    if (n == 0)
        return 1.0;

    // Inverting x and the sign of n when n < 0
    if (n < 0)
    {
        n = std::abs(n);
        x = 1 / x;
    }
    double pow{ myPow(x, n / 2) };
    pow *= pow;
    // For odd n
    if (n % 2 != 0)
        pow *= x;

    return pow;

}
#endif

// Iterative solution (O(log(n)) time complexity, O(1) space complexity)
#if 1
double myPow(double x, int n)
{
    double num{ 1.0 };
    long long nn{ n };
    // Inverting x and the sign of n when n < 0
    if (nn < 0)
    {
        nn = -nn;
        x = 1 / x;
    }
    // Working our way backwards through the squares of x
    while (nn > 0)
    {
        if (nn % 2 == 1)
        {
            num *= x;
            --nn;
        }
        else
        {
            x *= x;
            nn /= 2;
        }
    }
    return num;
}
#endif

#if 0
int main()
{
    // Provided test cases
    double thresh{ 0.0000000000001 };  // Answers can differ from the literals we're testing with due to machine precision limitations

    assert(std::abs(myPow(2.0, 10) - 1024.0) < thresh);
    
    assert(std::abs(myPow(2.1, 3) - 9.261) < thresh);

    assert(std::abs(myPow(2.0, -2) - 0.25) < thresh);

    assert(std::abs(myPow(1.0, -2147483648) - 1.0) < thresh);

    std::cout << "Success!\n";

    return 0;
}
#endif