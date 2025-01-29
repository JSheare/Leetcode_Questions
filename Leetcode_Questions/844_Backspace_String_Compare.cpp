#include <iostream>
#include <cassert>
#include <string>
#include <stack>

// Stack-based solution
#if 0
std::string helper(std::string& s, std::stack<char>& st)
{
    for (auto& c : s)
    {
        if (c == '#')
        {
            if (st.empty())
                continue;
            else
                st.pop();
        }
        else
            st.push(c);
    }
    std::string newS;
    while (!st.empty())
    {
        newS.push_back(st.top());
        st.pop();
    }
    return newS;
}

bool backspaceCompare(std::string s, std::string t)
{
    std::stack<char> st;
    return helper(s, st) == helper(t, st);
}
#endif

// Iterative solution
#if 1
bool backspaceCompare(std::string s, std::string t)
{
    int i{ static_cast<int>(s.length()) - 1 };
    int j{ static_cast<int>(t.length()) - 1 };
    int back;
    while (true)
    {
        back = 0;
        while (i >= 0 && (back > 0 || s[i] == '#'))
        {
            back += s[i] == '#' ? 1 : -1;
            --i;
        }
        back = 0;
        while (j >= 0 && (back > 0 || t[j] == '#'))
        {
            back += t[j] == '#' ? 1 : -1;
            --j;
        }
        if (i >= 0 && j >= 0 && s[i] == t[j])
        {
            --i;
            --j;
        }
        else
            break;
    }
    return i == -1 && j == -1;
}
#endif

#if 0
int main()
{
    // Provided test cases
    assert(backspaceCompare("ab#c", "ad#c") == true);

    assert(backspaceCompare("ab##", "c#d#") == true);

    assert(backspaceCompare("a#c", "b") == false);

    std::cout << "Success!\n";

    return 0;
}
#endif