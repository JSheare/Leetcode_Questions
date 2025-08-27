#include <iostream>
#include <cassert>
#include <stack>
#include <algorithm>
#include <string>

int longestValidParentheses(std::string s)
{
    int longest{ 0 };
    std::stack<int> st;
    st.push(-1);
    for (int i{ 0 }; i < s.size(); ++i)
    {
        if (s[i] == '(')
            st.push(i);
        else
            st.pop();
        if (st.empty())
            st.push(i);
        else
            longest = std::max(longest, i - st.top());
    }
    return longest;
}

#if 0
int main()
{
    // Provided test cases
    assert(longestValidParentheses("(()") == 2);

    assert(longestValidParentheses(")()())") == 4);

    assert(longestValidParentheses("") == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif