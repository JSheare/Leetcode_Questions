#include <iostream>
#include <assert.h>
#include <string>
#include <stack>
#include <ctype.h>


// Recursive solution
#if 0
std::string recurse(std::string& s, int& i)
{
    std::string substr;
    while (i < s.length() && s[i] != ']')
    {
        if (!std::isdigit(s[i]))
            substr += s[i++];
        else
        {
            int k{ 0 };
            while (i < s.length() && std::isdigit(s[i]))
            {
                k = k * 10 + s[i++] - '0';
            }
            ++i; // skipping '['
            std::string temp = recurse(s, i);
            ++i; // skipping ']'
            while (k-- > 0)
            {
                substr += temp;
            }
        }
    }
    return substr;
}

std::string decodeString(std::string s)
{
    int i{ 0 };
    return recurse(s, i);
}
#endif

// Stack-based solution
#if 1
std::string decodeString(std::string s)
{
    std::string decoded;
    std::stack<int> numS;
    std::stack<std::string> substrS;
    int k{ 0 };
    std::string substr;
    for (int i{ 0 }; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
            k = k * 10 + s[i] - '0';
        else if (s[i] == '[')
        {
            numS.push(k);
            substrS.push(decoded);
            k = 0;
            decoded = "";
        }
        else if (s[i] == ']')
        {
            substr = decoded;
            for (int j{ 1 }; j < numS.top(); ++j)
            {
                decoded += substr;
            }
            numS.pop();
            decoded = substrS.top() + decoded;
            substrS.pop();
        }
        else
            decoded += s[i];
    }
    return decoded;
}
#endif

#if 0
int main()
{
    //Provided test cases
    assert(decodeString("3[a]2[bc]") == "aaabcbc");

    assert(decodeString("3[a2[c]]") == "accaccacc");

    assert(decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");

    std::cout << "Success!\n";

    return 0;
}
#endif