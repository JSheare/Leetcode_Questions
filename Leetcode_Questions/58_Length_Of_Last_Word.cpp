#include <iostream>
#include <cassert>
#include <string>

int lengthOfLastWord(std::string s)
{
    int count{ 0 };
    for (int i{ static_cast<int>(s.size()) - 1 }; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            if (count > 0)
                return count;
        }
        else
            ++count;
    }
    return count;
}

#if 0
int main()
{
    // Provided test cases
    assert(lengthOfLastWord("Hello World") == 5);

    assert(lengthOfLastWord("   fly me   to   the moon  ") == 4);

    assert(lengthOfLastWord("luffy is still joyboy") == 6);

    std::cout << "Success!\n";

    return 0;
}
#endif