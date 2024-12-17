#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string prefix{ "" };
    std::sort(strs.begin(), strs.end());
    std::string first{ strs[0] };
    std::string last{ strs[strs.size() - 1] };
    for (int i{ 0 }; i < std::min(first.size(), last.size()); ++i)
    {
        if (first[i] != last[i])
            return prefix;

        prefix += first[i];
    }
    return prefix;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "flower", "flow", "flight" };
    assert(longestCommonPrefix(test1) == "fl");

    std::vector<std::string> test2{ "dog", "racecar", "car" };
    assert(longestCommonPrefix(test2) == "");

    std::cout << "Success!\n";

    return 0;
}
#endif