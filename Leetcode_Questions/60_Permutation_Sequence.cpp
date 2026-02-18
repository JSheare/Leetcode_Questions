#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::string getPermutation(int n, int k)
{
    std::vector<int> factorials(n + 1, 0);
    factorials[0] = 1;
    for (int i{ 1 }; i < factorials.size(); ++i)
    {
        factorials[i] = factorials[i - 1] * i;
    }
    std::vector<char> used(n + 1, 0);
    std::string permutation;
    for (int place{ 1 }; place <= n; ++place)
    {
        int i{ 1 };
        while (i <= n && used[i])
        {
            ++i;
        }
        int change{ factorials[n - place] };
        while (k > change)
        {
            ++i;
            if (used[i])
                continue;

            k -= change;
        }
        permutation += '0' + i;
        used[i] = 1;
    }
    return permutation;
}

#if 0
int main()
{
    // Provided test cases
    assert(getPermutation(3, 3) == "213");

    assert(getPermutation(4, 9) == "2314");

    assert(getPermutation(3, 1) == "123");

    std::cout << "Success!\n";

    return 0;
}
#endif