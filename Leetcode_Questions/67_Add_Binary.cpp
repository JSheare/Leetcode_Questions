#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>

std::string addBinary(std::string a, std::string b)
{
    std::string result;
    int i{ static_cast<int>(a.length()) - 1 };
    int j{ static_cast<int>(b.length()) - 1 };
    int carry{ 0 };
    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
        {
            carry += a[i] - '0';
            --i;
        }
        if (j >= 0)
        {
            carry += b[j] - '0';
            --j;
        }

        result += carry % 2 + '0';
        carry /= 2;
    }
    reverse(begin(result), end(result));
    return result;
}

# if 0
int main()
{
    // Provided test cases
    assert(addBinary("11", "1") == "100");

    assert(addBinary("1010", "1011") == "10101");

    std::cout << "Success!\n";

	return 0;
}
#endif