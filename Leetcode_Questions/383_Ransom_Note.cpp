#include <iostream>
#include <cassert>
#include <string>
#include <vector>

bool canConstruct(std::string ransomNote, std::string magazine)
{
    if (ransomNote.length() > magazine.length())
        return false;


    std::vector<int> freq(26, 0);
    for (char c : magazine)
    {
        ++freq[c - 'a'];
    }

    for (char c : ransomNote)
    {
        if (!freq[c - 'a'])
            return false;

        --freq[c - 'a'];
    }
    return true;
}

#if 0
int main()
{
    // Provided test cases
    assert(canConstruct("a", "b") == false);

    assert(canConstruct("aa", "ab") == false);

    assert(canConstruct("aa", "aab") == true);

    std::cout << "Success!\n";

	return 0;
}
#endif