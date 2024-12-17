#include <iostream>
#include <cassert>

bool isPalindrome(int x)
{
    if (x < 0 || (x != 0 && x % 10 == 0))
        return false;

    int reversed{ 0 };
    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return (x == reversed) || (x == reversed / 10);
}

#if 0
int main()
{
    //Provided test cases
    assert(isPalindrome(121) == true);

    assert(isPalindrome(-121) == false);

    assert(isPalindrome(10) == false);

    std::cout << "Success!";

    return 0;
}
#endif