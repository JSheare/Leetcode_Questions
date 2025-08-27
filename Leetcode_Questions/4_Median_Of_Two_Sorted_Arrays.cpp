#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
    // Math is predicated on the assumption that nums1 is the shorter one
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int left{ 0 };
    int right{ static_cast<int>(nums1.size()) };
    // Splitting the two arrays into two parts each, such that left1 + right1 + left2 + right2
    // is virtually sorted. Doing a binary search to find the partition points such that this is the case
    while (left <= right)
    {
        // The partition points are dependent on one another because, to find the median, 
        // len(left1 + right1) == len(left2 + right2) must be true
        int part1{ (left + right) / 2 };
        int part2{ static_cast<int>((nums1.size() + nums2.size() + 1) / 2 - part1) };

        int maxLeft1{ part1 == 0 ? INT_MIN : nums1[part1 - 1] };
        int minRight1{ part1 == nums1.size() ? INT_MAX : nums1[part1] };
        int maxLeft2{ part2 == 0 ? INT_MIN : nums2[part2 - 1] };
        int minRight2{ part2 == nums2.size() ? INT_MAX : nums2[part2] };

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        {
            if ((nums1.size() + nums2.size()) % 2 == 0)
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            else
                return std::max(maxLeft1, maxLeft2);
        }
        else if (maxLeft1 > minRight2)
            right = part1 - 1;
        else
            left = part1 + 1;
    }
    return 0;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1L{ 1, 3 };
    std::vector<int> test1R{ 2 };
    assert(findMedianSortedArrays(test1L, test1R) == 2.0);

    std::vector<int> test2L{ 1, 2 };
    std::vector<int> test2R{ 3, 4 };
    assert(findMedianSortedArrays(test2L, test2R) == 2.5);

    std::cout << "Success!\n";

    return 0;
}
#endif