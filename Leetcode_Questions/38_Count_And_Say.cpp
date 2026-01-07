#include <iostream>
#include <cassert>
#include <string>

std::string countAndSay(int n)
{
    std::string base{ "1" };
    --n;
    while (n > 0)
    {
        std::string compressed;
        int count{ 1 };
        for (int i{ 1 }; i < base.size(); ++i)
        {
            if (base[i] == base[i - 1])
                ++count;
            else
            {
                compressed.push_back(count + '0');
                compressed.push_back(base[i - 1]);
                count = 1;
            }
        }
        compressed.push_back(count + '0');
        compressed.push_back(base[base.size() - 1]);
        base = compressed;
        --n;
    }
    return base;
}

#if 0
int main()
{
    // Provided test cases
    assert(countAndSay(1) == "1");

    assert(countAndSay(4) == "1211");

    std::cout << "Success!\n";

    return 0;
}
#endif