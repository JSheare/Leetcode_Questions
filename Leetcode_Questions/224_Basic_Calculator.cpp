#include <iostream>
#include <cassert>
#include <stack>
#include <string>

int calculate_bc1(std::string s)
{
    std::stack<int> st;
    int sum{ 0 };
    int sign{ 1 };
    int num{ 0 };
    for (char c : s)
    {
        if (isdigit(c))
            num = num * 10 + (c - '0');
        else if (c == '+')
        {
            sum += sign * num;
            num = 0;
            sign = 1;
        }
        else if (c == '-')
        {
            sum += sign * num;
            num = 0;
            sign = -1;
        }
        else if (c == '(')
        {
            // Saving the outside state on the stack
            st.push(sum);
            st.push(sign);
            sum = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            sum += sign * num;
            num = 0;
            // Getting the correct sign from the outside state
            sum *= st.top();
            st.pop();
            // Adding the sum from the outside state back
            sum += st.top();
            st.pop();
        }
    }
    sum += sign * num;
    return sum;
}

#if 0
int main()
{
    // Provided test cases
    assert(calculate_bc1("1 + 1") == 2);

    assert(calculate_bc1(" 2-1 + 2 ") == 3);

    assert(calculate_bc1("(1+(4+5+2)-3)+(6+8)") == 23);

    std::cout << "Success!\n";

    return 0;
}
#endif