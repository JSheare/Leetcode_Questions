#include <iostream>
#include <cassert>
#include <vector>

int climbStairs(int n)
{
    std::vector<int> cache(n + 2, 0);
    cache[0] = 0;
    cache[1] = 1;
    for (int i{ 2 }; i < n + 2; ++i)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache[n + 2 - 1];
}

#if 0
int main()
{
    // Provided test cases
    assert(climbStairs(2) == 2);
    
    assert(climbStairs(3) == 3);

    std::cout << "Success!\n";

    return 0;
}
#endif