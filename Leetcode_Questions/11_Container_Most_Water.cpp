#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height)
{
    int left{ 0 };
    int right{ static_cast<int>(height.size()) - 1 };
    int maxArea{ 0 };
    while (left < right)
    {
        if (height[left] < height[right])
        {
            maxArea = std::max(maxArea, (right - left) * height[left]);
            ++left;
        }
        else
        {
            maxArea = std::max(maxArea, (right - left) * height[right]);
            --right;
        }
    }
    return maxArea;
}

#if 0
int main()
{
    // Provided test case
    std::vector<int> test1{ 1, 8, 6, 2, 5, 4, 5, 3, 7 };
    assert(maxArea(test1) == 49);

    std::cout << "Success!\n";

    return 0;
}
#endif