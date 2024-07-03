#include <iostream>
#include <assert.h>
#include <vector>

std::vector<int> countBits(int n)
{
    std::vector<int> numBits(n + 1);
    for (int i{ 1 }; i <= n; ++i)
    {
        numBits[i] = numBits[i / 2] + i % 2;
    }
    return numBits;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> correct1{ 0, 1, 1 };
    assert(countBits(2) == correct1);

    std::vector<int> correct2{ 0, 1, 1, 2, 1, 2 };
    assert(countBits(5) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif