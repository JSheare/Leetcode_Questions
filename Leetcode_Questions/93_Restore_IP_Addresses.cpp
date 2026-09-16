#include <iostream>
#include <cassert>
#include <vector>
#include <string>

void restoreIpAddressesHelper(std::vector<std::string>& addresses, std::string& s, std::vector<std::string>& octets, int level, int start)
{
    if (level == 4 && start == s.size())
    {
        std::string address{ "" };
        for (int i{ 0 }; i < octets.size(); ++i)
        {
            address += octets[i];
            if (i < octets.size() - 1)
                address += '.';
        }
        addresses.push_back(address);
        return;
    }

    std::string octet{ "" };
    int size{ 0 };
    // An octet will never have more than 3 digits, hence the extra condition
    for (int i{ start }; start - i < 3 && i < s.size(); ++i)
    {
        octet += s[i];
        size = size * 10 + (s[i] - '0');

        // Checking that the octet isn't too large
        if (size > 255)
            return;

        // Checking to make sure there isn't a leading zero
        if (octet[0] == '0' && octet.size() > 1)
            return;

        octets.push_back(octet);
        restoreIpAddressesHelper(addresses, s, octets, level + 1, i + 1);
        octets.pop_back();
    }
}

std::vector<std::string> restoreIpAddresses(std::string s)
{
    if (s.size() < 4 || s.size() > 12)
        return {};

    std::vector<std::string> addresses;
    std::vector<std::string> octets;
    restoreIpAddressesHelper(addresses, s, octets, 0, 0);
    return addresses;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> answer1{ "255.255.11.135", "255.255.111.35" };
    assert(restoreIpAddresses("25525511135") == answer1);

    std::vector<std::string> answer2{ "0.0.0.0" };
    assert(restoreIpAddresses("0000") == answer2);

    std::vector<std::string> answer3{ "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3" };
    assert(restoreIpAddresses("101023") == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif