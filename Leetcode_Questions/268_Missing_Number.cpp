#include <iostream>
#include <assert.h>
#include <vector>

// Bit manipulation solution
// Based on the following idea: 
// 1) XOR is associative: a ^ (b ^ c) = (a ^ b) ^ c;
// 2) XOR is commutative: a ^ b = b ^ a;
// And 3) A ^ A = 0.
// Based on 1 and 2, we can XOR things together in any order we like and still end up with the same surviving value,
// so we'll XOR each number from the actual sum of n and each number from the expected sum of n together.
// By 3, every number from the actual sum cancels out its corresponding number from the expected sum, 
// leaving us with the missing number.
#if 0
int missingNumber(std::vector<int>& nums)
{
    int xorry{ 0 };
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        xorry ^= i;
        xorry ^= nums[i];
    }
    return xorry;
}
#endif

// Math solution
#if 1
int missingNumber(std::vector<int>& nums)
{
    int n{ static_cast<int>(nums.size()) };
    int sum{ 0 };
    for (int i{ 0 }; i < n; ++i)
    {
        sum += nums[i];
    }
    // The sum of n nums is just n*(n+1)/2
    return n * (n + 1) / 2 - sum;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 3, 0, 1 };
    std::cout << missingNumber(test1);
    assert(missingNumber(test1) == 2);

    std::vector<int> test2{ 0, 1 };
    assert(missingNumber(test2) == 2);

    std::vector<int> test3{ 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    assert(missingNumber(test3) == 8);

    std::cout << "Success!\n";

    return 0;
}
#endif