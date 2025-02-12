#include <iostream>
#include <cassert>
#include <vector>

int trap(std::vector<int>& height)
{
    int n{ static_cast<int>(height.size()) };
    if (n <= 2)
        return 0;

    int maxLeft{ height[0] };
    int maxRight{ height[n - 1] };
    // The left and rightmost bars can't contribute anything because they're edges
    int left{ 1 };
    int right{ n - 2 };
    int trapped{ 0 };
    while (left <= right)
    {
        if (maxLeft < maxRight)
        {
            if (height[left] > maxLeft)
                maxLeft = height[left];
            else
                trapped += maxLeft - height[left];

            ++left;
        }
        else
        {
            if (height[right] > maxRight)
                maxRight = height[right];
            else
                trapped += maxRight - height[right];

            --right;
        }
    }
    return trapped;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    assert(trap(test1) == 6);

    std::vector<int> test2{ 4, 2, 0, 3, 2, 5 };
    assert(trap(test2) == 9);

    std::cout << "Success!\n";

    return 0;
}
#endif
