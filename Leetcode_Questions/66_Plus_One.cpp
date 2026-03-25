#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits)
{
    for (int i{ static_cast<int>(digits.size()) - 1 }; i >= 0; --i)
    {
        if (digits[i] < 9)
        {
            ++digits[i];
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3 };
    std::vector<int> answer1{ 1, 2, 4 };
    assert(plusOne(test1) == answer1);

    std::vector<int> test2{ 4, 3, 2, 1 };
    std::vector<int> answer2{ 4, 3, 2, 2 };
    assert(plusOne(test2) == answer2);

    std::vector<int> test3{ 9 };
    std::vector<int> answer3{ 1, 0 };
    assert(plusOne(test3) == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif