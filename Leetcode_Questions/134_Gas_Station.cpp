#include <iostream>
#include <cassert>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    int total{ 0 };
    int tank{ 0 };
    int start{ 0 };
    for (int i{ 0 }; i < gas.size(); ++i)
    {
        total += (gas[i] - cost[i]);
        tank += (gas[i] - cost[i]);
        if (tank < 0)
        {
            tank = 0;
            start = i + 1;
        }
    }
    if (total >= 0)
        return start;

    return -1;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> gas1{ 1, 2, 3, 4, 5 };
    std::vector<int> cost1{ 3, 4, 5, 1, 2 };
    assert(canCompleteCircuit(gas1, cost1) == 3);

    std::vector<int> gas2{ 2, 3, 4 };
    std::vector<int> cost2{ 3, 4, 3 };
    assert(canCompleteCircuit(gas2, cost2) == -1);

    std::cout << "Success!\n";

    return 0;
}
#endif