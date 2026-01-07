#include <iostream>
#include <cassert>
#include <string>
#include <vector>

std::string multiply(std::string num1, std::string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    // Doing long multiplication and storing the results in an array
    std::vector<int> result(num1.size() + num2.size(), 0);
    for (int i{ static_cast<int>(num1.size()) - 1 }; i >= 0; --i)
    {
        for (int j{ static_cast<int>(num2.size()) - 1 }; j >= 0; --j)
        {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    int i{ 0 };
    std::string s;
    while (result[i] == 0)
    {
        ++i;
    }
    while (i < result.size())
    {
        s.push_back(result[i++] + '0');
    }
    return s;
}

#if 0
int main()
{
    // Provided test cases
    assert(multiply("2", "3") == "6");

    assert(multiply("123", "456") == "56088");

    std::cout << "Success!\n";

    return 0;
}
#endif