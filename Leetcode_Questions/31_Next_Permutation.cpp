#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>


void nextPermutation(std::vector<int>& v) {
    if (v.size() == 1)
        return;

    if (v.size() == 2)
    {
        std::swap(v[1], v[0]);
        return;
    }
    int i{ static_cast<int>(v.size()) - 2 };
    while (i >= 0)
    {
        if (v[i] < v[i + 1])
            break;

        --i;
    }
    if (i == -1)
    {
        std::sort(v.begin(), v.end());
        return;
    }

    std::sort(v.begin() + i + 1, v.end());
    for (int j{ i + 1 }; j < v.size(); ++j)
    {
        if (v[i] < v[j])
        {
            std::swap(v[i], v[j]);
            return;
        }
    }
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 1, 2, 3 };
    std::vector<int> correct1{ 1, 3, 2 };
    nextPermutation(test1);
    assert(test1 == correct1);

    std::vector<int> test2{ 3, 2, 1 };
    std::vector<int> correct2{ 1, 2, 3 };
    nextPermutation(test2);
    assert(test2 == correct2);

    std::vector<int> test3{ 1, 1, 5 };
    std::vector<int> correct3{ 1, 5, 1 };
    nextPermutation(test3);
    assert(test3 == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif