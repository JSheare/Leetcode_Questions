#include "MedianFinder.h"

void MedianFinder::addNum(int num)
{
    if (leftHalf.size() == 0)
        leftHalf.push(num);
    else
    {
        if (num < leftHalf.top())
            leftHalf.push(num);
        else
            rightHalf.push(num);

        // Making sure that the two halves are roughly balanced
        balance();
    }
}

double MedianFinder::findMedian()
{
    if (leftHalf.size() == rightHalf.size())
        return static_cast<double>(leftHalf.top() + rightHalf.top()) / 2.0;

    return leftHalf.top();
}

void MedianFinder::balance()
{
    // Slightly favors left half
    if (leftHalf.size() == rightHalf.size() + 2)
    {
        rightHalf.push(leftHalf.top());
        leftHalf.pop();
    }
    else if (leftHalf.size() + 1 == rightHalf.size())
    {
        leftHalf.push(rightHalf.top());
        rightHalf.pop();
    }
}

