#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

void parenthesisHelper(std::vector<std::string>& combos, std::string& combo, int nOpen, int nClose)
{
    if (!nOpen && !nClose)
    {
        combos.push_back(combo);
        return;
    }
    if (nOpen)
    {
        combo.push_back('(');
        parenthesisHelper(combos, combo, nOpen - 1, nClose);
        combo.pop_back();
    }
    if (nClose > nOpen)
    {
        combo.push_back(')');
        parenthesisHelper(combos, combo, nOpen, nClose - 1);
        combo.pop_back();
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> combos;
    std::string combo;
    parenthesisHelper(combos, combo, n, n);
    return combos;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> correct1{ "((()))", "(()())", "(())()", "()(())", "()()()" };
    assert(generateParenthesis(3) == correct1);

    std::vector<std::string> correct2{ "()" };
    assert(generateParenthesis(1) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif