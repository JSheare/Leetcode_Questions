#include <iostream>
#include <assert.h>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
    if (matrix.size() == 0)
        return false;

    int m{ static_cast<int>(matrix.size()) };
    int n{ static_cast<int>(matrix[0].size()) };
    int rLow{ 0 };
    int rHigh{ m - 1 };
    // Binary search of the rows to find the correct one
    while (rLow <= rHigh)
    {
        int rMid{ rLow + (rHigh - rLow) / 2 };
        if (target >= matrix[rMid][0] && target <= matrix[rMid][n - 1])
        {
            int low{ 0 };
            int high{ n - 1 };
            // Binary search of the correct row to find the target value (if it's present)
            while (low <= high)
            {
                int mid{ low + (high - low) / 2 };
                if (matrix[rMid][mid] == target)
                    return true;
                else if (matrix[rMid][mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return false;
        }
        else if (matrix[rMid][0] > target)
            rHigh = rMid - 1;
        else
            rLow = rMid + 1;
    }
    return false;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<int>> test1{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60} };
    assert(searchMatrix(test1, 3) == true);

    std::vector<std::vector<int>> test2{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60} };
    assert(searchMatrix(test2, 13) == false);

    std::cout << "Success!\n";

    return 0;
}
#endif