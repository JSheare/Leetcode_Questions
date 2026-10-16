#include <iostream>
#include <cassert>
#include <vector>

int numTrees(int n)
{
    // For any root i in [1, n], there will be i - 1 nodes in the left subtree and n - i nodes in the right subtree
    // So, the number of permutations for root i is P(i - 1) * P(n - i)
    // To get the total number of permutations, we just sum over all possible values of i, i.e. over [1, n]:
    // P(n) = sum{i=1}^{n} P(i - 1) * P(n - i), where P(0) = P(1) = 1
    std::vector<int> numPerms(n + 1, 1);
    for (int i{ 2 }; i <= n; ++i)
    {
        int total{ 0 };
        for (int j{ 1 }; j <= i; ++j)
        {
            total += numPerms[j - 1] * numPerms[i - j];
        }
        numPerms[i] = total;
    }
    return numPerms[n];
}

#if 0
int main()
{
    // Provided test cases
    assert(numTrees(3) == 5);

    assert(numTrees(1) == 1);

    std::cout << "Success!\n";

    return 0;
}
#endif