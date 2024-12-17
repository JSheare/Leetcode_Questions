#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices)
{
    if (prices.size() < 2)
        return 0;

    int maxProfit{ 0 };
    int minPrice{ prices[0] };
    for (int i{ 1 }; i < prices.size(); ++i)
    {
        int profit{ prices[i] - minPrice };
        maxProfit = std::max(profit, maxProfit);
        minPrice = std::min(prices[i], minPrice);
    }

    return maxProfit;
}

#if 0
int main()
{
    std::vector test1{ 7, 1, 5, 3, 6, 4 };
    int answer1{ 5 };
    assert(maxProfit(test1) == answer1);

    std::vector test2{ 7, 6, 4, 3, 1 };
    int answer2{ 0 };
    assert(maxProfit(test2) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif