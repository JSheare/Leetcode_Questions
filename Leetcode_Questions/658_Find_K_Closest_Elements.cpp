#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

// Binary search/two pointers/priority queue solution (inside out)
#if 0
std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
{
    // Finding the location of the element (or closest) with a binary search
    int left{ static_cast<int>(lower_bound(arr.begin(), arr.end(), x) - arr.begin()) };
    if (left == arr.size() || arr[left] != x)
        --left;

    int right{ left + 1 };
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    while (pq.size() < k)
    {
        if (left < 0)
        {
            pq.push(arr[right]);
            ++right;
            continue;
        }
        if (right == arr.size())
        {
            pq.push(arr[left]);
            --left;
            continue;
        }
        int leftDiff{ std::abs(arr[left] - x) };
        int rightDiff{ std::abs(arr[right] - x) };
        if (leftDiff < rightDiff)
        {
            pq.push(arr[left]);
            --left;
        }
        else if (rightDiff < leftDiff)
        {
            pq.push(arr[right]);
            ++right;
        }
        else
        {
            if (arr[left] < arr[right])
            {
                pq.push(arr[left]);
                --left;
            }
            else
            {
                pq.push(arr[right]);
                ++right;
            }
        }
    }
    std::vector<int> kClosest;
    while (!pq.empty())
    {
        kClosest.push_back(pq.top());
        pq.pop();
    }
    return kClosest;
}
#endif

// Two pointer approach (outside in)
#if 1
std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
{
    int left{ 0 };
    int right{ static_cast<int>(arr.size()) - 1 };
    while (right - left >= k)
    {
        if (abs(arr[left] - x) > abs(arr[right] - x))
            ++left;
        else
            --right;
    }
    std::vector<int> kClosest;
    for (int i{ left }; i <= right; ++i)
    {
        kClosest.push_back(arr[i]);
    }
    return kClosest;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3, 4, 5 };
    std::vector<int> correct1{ 1, 2, 3, 4 };
    assert(findClosestElements(test1, 4, 3) == correct1);

    std::vector<int> test2{ 1, 1, 2, 3, 4, 5 };
    std::vector<int> correct2{ 1, 1, 2, 3 };
    assert(findClosestElements(test2, 4, -1) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif