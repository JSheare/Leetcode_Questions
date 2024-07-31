#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
{
    std::vector<int> wait(temperatures.size(), 0);
    std::stack<int> s;
    for (int i{ 0 }; i < temperatures.size(); ++i)
    {
        while (!s.empty() && temperatures[i] > temperatures[s.top()])
        {
            int prevIndx{ s.top() };
            s.pop();
            wait[prevIndx] = i - prevIndx;
        }
        s.push(i);
    }
    return wait;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 73, 74, 75, 71, 69, 72, 76, 73 };
    std::vector<int> correct1{ 1, 1, 4, 2, 1, 1, 0, 0 };
    assert(dailyTemperatures(test1) == correct1);

    std::vector<int> test2{ 30, 40, 50, 60 };
    std::vector<int> correct2{ 1, 1, 1, 0 };
    assert(dailyTemperatures(test2) == correct2);

    std::vector<int> test3{ 30, 60, 90 };
    std::vector<int> correct3{ 1, 1, 0 };
    assert(dailyTemperatures(test3) == correct3);
    
    std::cout << "Success!\n";

    return 0;
}
#endif