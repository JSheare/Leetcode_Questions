#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

std::vector<int> grayCode(int n)
{
    std::vector<int> codeSequence;
    int limit{ static_cast<int>(std::pow(2, n)) };
    for (int i{ 0 }; i < limit; ++i)
    {
        int gray{ i ^ (i >> 1) };
        codeSequence.push_back(gray);
    }
    return codeSequence;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> answer1{ 0, 1, 3, 2 };
    assert(grayCode(2) == answer1);

    std::vector<int> answer2{ 0, 1 };
    assert(grayCode(1) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif
