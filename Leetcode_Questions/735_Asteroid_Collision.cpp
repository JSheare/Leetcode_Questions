#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>

std::vector<int> asteroidCollision(std::vector<int>& asteroids)
{
    std::stack<int> s;
    for (auto& a : asteroids)
    {
        if (a > 0)
            s.push(a);

        else
        {
            // Continue until you encounter an asteroid that the current one can't destroy
            while (!s.empty() && s.top() > 0 && s.top() < -a)
            {
                s.pop();
            }
            // If the stack is empty or the asteroids are moving in the same direction, push current asteroid to stack
            if (s.empty() || s.top() < 0)
                s.push(a);

            // If the asteroids are of the same magnitude, they both explode, so remove the one that's still on the stack
            if (!s.empty() && s.top() == -a)
                s.pop();

        }
    }
    // Reversing stack elements as we pop them
    std::vector<int> survivors(s.size());
    int i{ static_cast<int>(s.size()) - 1 };
    while (!s.empty())
    {
        survivors[i--] = s.top();
        s.pop();
    }
    return survivors;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> test1{ 5, 10, -5 };
    std::vector<int> correct1{ 5, 10 };
    assert(asteroidCollision(test1) == correct1);

    std::vector<int> test2{ 8, -8 };
    std::vector<int> correct2{};
    assert(asteroidCollision(test2) == correct2);

    std::vector<int> test3{ 10, 2, -5 };
    std::vector<int> correct3{ 10 };
    assert(asteroidCollision(test3) == correct3);

    std::cout << "Success!\n";

    return 0;
}
#endif