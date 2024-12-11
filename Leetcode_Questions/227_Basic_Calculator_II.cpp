#include <iostream>
#include <assert.h>
#include <stack>
#include <string>

// Postfix-ish solution
#if 0
int calculate(std::string s)
{
    auto precedence = [](char c) {return c == '*' || c == '/'; };
    std::stack<char> ops;
    std::stack<int> nums;
    int currNum{ 0 };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        char c{ s[i] };
        if (std::isdigit(c))
            currNum = currNum * 10 + (c - '0');

        if (!std::isdigit(c) && c != ' ' || i == s.length() - 1)
        {
            nums.push(currNum);
            while (!ops.empty() && precedence(c) <= precedence(ops.top()))
            {
                int num1{ nums.top() };
                nums.pop();
                int num2{ nums.top() };
                nums.pop();
                char currOp{ ops.top() };
                ops.pop();
                if (currOp == '*')
                    nums.push(num2 * num1);
                else if (currOp == '/')
                    nums.push(num2 / num1);
                else if (currOp == '+')
                    nums.push(num2 + num1);
                else if (currOp == '-')
                    nums.push(num2 - num1);
            }
            if (!std::isdigit(c) && c != ' ')
                ops.push(c);

            currNum = 0;
        }
    }
    return nums.top();
}
#endif

// In-place solution
#if 1
int calculate(std::string s)
{
    int result{ 0 };
    int lastNum{ 0 };
    int currNum{ 0 };
    char lastSign{ '+' };
    for (int i{ 0 }; i < s.length(); ++i)
    {
        char c{ s[i] };
        if (isdigit(c))
            currNum = currNum * 10 + (c - '0');

        if (!isdigit(c) && c != ' ' || i == s.length() - 1)
        {
            if (lastSign == '+' || lastSign == '-')
            {
                result += lastNum;
                lastNum = lastSign == '+' ? currNum : -currNum;
            }
            else if (lastSign == '*')
                lastNum = lastNum * currNum;
            else if (lastSign == '/')
                lastNum = lastNum / currNum;

            lastSign = c;
            currNum = 0;
        }
    }
    result += lastNum;
    return result;
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(calculate("3+2*2") == 7);

    assert(calculate(" 3/2 ") == 1);

    assert(calculate(" 3+5 / 2 ") == 5);

    std::cout << "Success!\n";

    return 0;
}
#endif
