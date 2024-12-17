#include <iostream>
#include <cassert>

uint32_t reverseBits(uint32_t n)
{
    uint32_t reversed{ 0 };
    for (int i{ 0 }; i < 32; ++i)
    {
        reversed <<= 1; // Making a new place for this bit
        // n & 1 captures the current bit of n
        // Oring n & 1 with reversed saves the bit
        reversed = reversed | (n & 1);
        n >>= 1;  // Moving to n's next bit
    }
    return reversed;
}

#if 0
int main()
{
    // Provided test cases
    
    // Input: 00000010100101000001111010011100
    // Expected output: 00111001011110000010100101000000
    assert(reverseBits(43261596) == 964176192);

    // Input: 11111111111111111111111111111101
    // Expected output: 10111111111111111111111111111111
    assert(reverseBits(4294967293) == 3221225471);

    std::cout << "Success!\n";

    return 0;
}
#endif