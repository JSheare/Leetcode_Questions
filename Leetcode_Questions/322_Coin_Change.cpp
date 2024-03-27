#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

int coinChange(std::vector<int>& coins, int amount)
{
    std::vector<int> cache(amount + 1, amount + 1);
    cache[0] = 0;
    for (int coin : coins)
    {
        for (int i{ coin }; i < (amount + 1); ++i)
        {
            cache[i] = std::min(cache[i], cache[i - coin] + 1);
        }
    }
    return cache[amount] > amount ? -1 : cache[amount];
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 5 };
    assert(coinChange(test1, 11) == 3);

    std::vector<int> test2{ 2 };
    assert(coinChange(test2, 3) == -1);

    std::vector<int> test3{ 1 };
    assert(coinChange(test3, 0) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif