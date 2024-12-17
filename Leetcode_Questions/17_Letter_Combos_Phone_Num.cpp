#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>

void makeCombos(std::string& digits, std::unordered_map<char, std::vector<char>>& mappings, std::vector<std::string>& combos,
    int index, std::string& combo)
{
    if (index == digits.length())
    {
        combos.push_back(combo);
        return;
    }
    for (auto& c : mappings[digits[index]])
    {
        combo.push_back(c);
        makeCombos(digits, mappings, combos, index + 1, combo);
        combo.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    if (digits.length() == 0)
        return {};

    std::unordered_map<char, std::vector<char>> mappings;
    mappings['2'] = { 'a', 'b', 'c' };
    mappings['3'] = { 'd', 'e', 'f' };
    mappings['4'] = { 'g', 'h','i' };
    mappings['5'] = { 'j', 'k', 'l' };
    mappings['6'] = { 'm', 'n', 'o' };
    mappings['7'] = { 'p', 'q', 'r', 's' };
    mappings['8'] = { 't', 'u', 'v' };
    mappings['9'] = { 'w', 'x', 'y', 'z' };

    std::vector<std::string> combos;
    std::string combo{ "" };
    makeCombos(digits, mappings, combos, 0, combo);
    return combos;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> answer1{ "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
    assert(letterCombinations("23") == answer1);

    std::vector<std::string> answer2{};
    assert(letterCombinations("") == answer2);

    std::vector<std::string> answer3{ "a", "b", "c" };
    assert(letterCombinations("2") == answer3);

    std::cout << "Success!\n";

    return 0;
}
#endif