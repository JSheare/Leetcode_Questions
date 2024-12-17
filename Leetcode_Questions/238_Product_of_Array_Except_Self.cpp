#include <iostream>
#include <cassert>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    int n{ static_cast<int>(nums.size()) };
    std::vector<int> answer(n, 1);
    // Taking the product from the right side
    for (int i{ n - 2 }; i >= 0; --i)
    {
        answer[i] = nums[i + 1] * answer[i + 1];
    }
    // Taking the product from the left side
    int leftProd{ 1 };
    for (int j{ 1 }; j < n; ++j)
    {
        leftProd *= nums[j - 1];
        answer[j] *= leftProd;
    }
    return answer;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3, 4 };
    std::vector<int> correct1{ 24, 12, 8, 6 };
    assert(productExceptSelf(test1) == correct1);

    std::vector<int> test2{ -1, 1, 0, -3, 3 };
    std::vector<int> correct2{ 0, 0, 9, 0, 0 };
    assert(productExceptSelf(test2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif