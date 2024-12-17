#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int threeSumClosest(std::vector<int>& nums, int target)
{
    std::sort(nums.begin(), nums.end());
    int best{ INT_MAX };
    int bestDiff{ INT_MAX };
    for (int i{ 0 }; i < nums.size() - 2; ++i)
    {
        int l{ i + 1 };
        int r{ static_cast<int>(nums.size()) - 1 };
        while (l < r)
        {
            int total{ nums[i] + nums[l] + nums[r] };
            if (total == target)
                return total;
            else if (total < target)
                ++l;
            else
                --r;

            int diff{ abs(target - total) };
            if (diff < bestDiff)
            {
                best = total;
                bestDiff = diff;
            }
        }
    }
    return best;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ -1, 2, 1, -4 };
    assert(threeSumClosest(test1, 1) == 2);

    std::vector<int> test2{ 0, 0, 0 };
    assert(threeSumClosest(test2, 1) == 0);

    std::cout << "Success!\n";

    return 0;
}
#endif