#include <iostream>
#include <cassert>

int hammingWeight(int n)
{
    int counter{ 0 };
    while (n)
    {
        if (n & 1)
            ++counter;

        n = n >> 1;
    }
    return counter;
}

#if 0
int main()
{
    // Provided test cases
    assert(hammingWeight(11) == 3);

    assert(hammingWeight(128) == 1);

    assert(hammingWeight(2147483645) == 30);

    std::cout << "Success!\n";

    return 0;
}
#endif