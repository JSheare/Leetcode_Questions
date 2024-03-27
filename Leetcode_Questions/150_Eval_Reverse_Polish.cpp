#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <stack>

int evalRPN(std::vector<std::string>& tokens)
{
    std::stack<int> digits;
    for (std::string& token : tokens)
    {
        if (token.length() > 1 || isdigit(token[0]))
            digits.push(std::stoi(token));
        else
        {
            int op2{ digits.top() };
            digits.pop();
            int op1{ digits.top() };
            digits.pop();
            if (token[0] == '+')
                digits.push(op1 + op2);
            else if (token[0] == '-')
                digits.push(op1 - op2);
            else if (token[0] == '*')
                digits.push(op1 * op2);
            else
                digits.push(op1 / op2);
        }
    }
    return digits.top();
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::string> test1{ "2","1","+","3","*" };
    assert(evalRPN(test1) == 9);

    std::vector<std::string> test2{ "4","13","5","/","+" };
    assert(evalRPN(test2) == 6);

    std::vector<std::string> test3{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    assert(evalRPN(test3) == 22);

    std::cout << "Success!\n";

    return 0;
}
#endif