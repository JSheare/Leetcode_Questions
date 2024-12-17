#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

// Standard sorting solution
#if 1
std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
{
    std::vector<std::vector<int>> answer(k);
    std::sort(points.begin(), points.end(),
        [](std::vector<int>& p1, std::vector<int>& p2) {
            return sqrt(pow(p1[0], 2) + pow(p1[1], 2)) < sqrt(pow(p2[0], 2) + pow(p2[1], 2)); });
    for (int i{ 0 }; i < k; ++i)
    {
        answer[i] = points[i];
    }
    return answer;
}
#endif

// Quickselect solution
#if 0
double distance(std::vector<int>& coords)
{
    return sqrt(pow(coords[0], 2) + pow(coords[1], 2));
}

int partition(std::vector<std::vector<int>>& points, int left, int right, int pivot)
{
    swap(points[pivot], points[right]); // Move pivot to the end
    int storeIndex{ left };
    for (int i{ left }; i < right; ++i)
    {
        if (distance(points[i]) < distance(points[right])) // comparison between current point and pivot
        {
            swap(points[i], points[storeIndex]);
            ++storeIndex;
        }
    }
    swap(points[right], points[storeIndex]); // Move pivot to it's final place
    return storeIndex;
}

void quickSelect(std::vector<std::vector<int>>& points, int left, int right, int k)
{
    if (left == right)
        return;

    int pivot{ left };
    pivot = partition(points, left, right, pivot);
    if (k == pivot)
        return;
    else if (k < pivot)
        quickSelect(points, left, pivot - 1, k);
    else
        quickSelect(points, pivot + 1, right, k);

}

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
{
    std::vector<std::vector<int>> answer(k);
    quickSelect(points, 0, static_cast<int>(points.size()) - 1, k);
    for (int i{ 0 }; i < k; ++i)
    {
        answer[i] = points[i];
    }
    return answer;
}
#endif

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{ {1, 3}, {-2, 2} };
    std::vector<std::vector<int>> correct1{ {-2, 2} };
    assert(kClosest(test1, 1) == correct1);

    std::vector<std::vector<int>> test2{ {3, 3}, {5, -1}, {-2, 4} };
    std::vector<std::vector<int>> correct2{ {3, 3}, {-2, 4} };
    assert(kClosest(test2, 2) == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif