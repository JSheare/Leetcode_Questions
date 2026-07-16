#include <iostream>
#include <cassert>

int mySqrt(int x)
{
    if (x == 0)
        return x;

    int low{ 1 };
    int high{ x };
    while (low <= high)
    {
        int mid{ low + (high - low) / 2 };
        if (mid == x / mid)
            return mid;
        else if (mid > x / mid)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}

#if 0
int main()
{
    // Provided test cases
    assert(mySqrt(4) == 2);

    assert(mySqrt(8) == 2);

    std::cout << "Success!\n";

    return 0;
}
#endif