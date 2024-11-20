#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <algorithm>

std::string largestNumber(std::vector<int>& nums)
{
    std::vector<std::string> numStrs;
    for (auto& num : nums)
    {
        numStrs.push_back(std::to_string(num));
    }
    std::sort(numStrs.begin(), numStrs.end(),
        [](std::string& str1, std::string& str2) {return str1 + str2 > str2 + str1; });
    if (numStrs[0] == "0")
        return "0";

    std::string number;
    for (auto& str : numStrs)
    {
        number += str;
    }
    return number;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 10, 2 };
    assert(largestNumber(test1) == "210");

    std::vector<int> test2{ 3, 30, 34, 5, 9 };
    assert(largestNumber(test2) == "9534330");

    std::cout << "Success!\n";

    return 0;
}
#endif
