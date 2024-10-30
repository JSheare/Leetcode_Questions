#ifndef RANDOMPICKWEIGHTED_H
#define RANDOMPICKWEIGHTED_H

#include <vector>
#include <random>

class RandomPickWeighted
{
public:
    /* The point of the prefix sum is to create a wider or smaller range of numbers that can map to each index
        according to the given weights. If the difference between weights for i and i + 1 is large, then there's a
        large amount of separation between their prefix sums, and hence it's more likely that we'll generate a random
        number that falls between their sums. Conversely, if the separation distance is small, then it's less likely we'll
        generate a random number that falls between their sums. Thus, all we need to do is look for where our
        randomly-generated number would fall using a binary search of the prefix sums, and the likelihood of it falling
        anywhere in particular will be weighted implicitly.
        */
    RandomPickWeighted(std::vector<int>& w)
    {
        prefix.resize(w.size());
        prefix[0] = w[0];
        for (int i{ 1 }; i < w.size(); ++i)
        {
            prefix[i] = prefix[i - 1] + w[i];
        }
    }

    int pickIndex()
    {
        int target{ std::rand() % prefix.back() + 1 };  // Returns an int on the range [0, cumulative sum of w]
        int low{ 0 };
        int high{ static_cast<int>(prefix.size()) };
        while (low < high)
        {
            int mid{ low + (high - low) / 2 };
            if (target > prefix[mid])
                low = mid + 1;

            else
                high = mid;

        }
        return low;
    }
private:
    std::vector<int> prefix;
};



#endif