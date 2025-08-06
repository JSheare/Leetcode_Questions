#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <algorithm>

int largestRectangleArea(std::vector<int>& heights)
{
    // Stack keeps track of potentially maximal rectangles that haven't been checked yet
    std::stack<int> st;
    int maxArea{ 0 };
    for (int i{ 0 }; i <= heights.size(); ++i)
    {
        // Dummy height of zero at the end so that we can check leftover potential rectangles
        int currHeight{ i == heights.size() ? 0 : heights[i] };
        // Popping from the stack until we encounter a potential rectangle that can't be at least partially 
        // combined with the current one (older rectangle height < current rectangle height)
        while (!st.empty() && heights[st.top()] > currHeight)
        {
            int height{ heights[st.top()] };
            st.pop();
            // The width of each rectangle is always defined by i - previous rectangle's rightmost index
            // When the stack isn't empty, then a previous rectangle exists, and width = i - st.top() - 1
            // When the stack is empty, the width is just the whole array up to this point (width = i - 0)
            maxArea = std::max((st.empty() ? i : i - st.top() - 1) * height, maxArea);
        }
        // Keeping track of this potential rectangle by putting the index of its right boundary on the stack
        st.push(i);
    }
    return maxArea;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 2, 1, 5, 6, 2, 3 };
    assert(largestRectangleArea(test1) == 10);

    std::vector<int> test2{ 2, 4 };
    assert(largestRectangleArea(test2) == 4);

    std::cout << "Success!\n";

    return 0;
}
#endif