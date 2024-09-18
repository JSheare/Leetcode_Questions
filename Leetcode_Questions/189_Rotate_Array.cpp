#include <iostream>
#include <assert.h>
#include <vector>

void rotate(std::vector<int>& nums, int k)
{
    k = k % nums.size();
    if (k == 0)
        return;

    reverse(nums.begin(), nums.begin() + (nums.size() - k));
    reverse(nums.begin() + (nums.size() - k), nums.end());
    reverse(nums.begin(), nums.end());
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> correct1{ 5, 6, 7, 1, 2, 3, 4 };
    rotate(test1, 3);
    assert(test1 == correct1);

    std::vector<int> test2{ -1, -100, 3, 99 };
    std::vector<int> correct2{ 3, 99, -1, -100 };
    rotate(test2, 2);
    assert(test2 == correct2);
    
    std::cout << "Success!\n";

    return 0;
}
#endif