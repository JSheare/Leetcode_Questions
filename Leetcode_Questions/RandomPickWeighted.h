#ifndef RANDOMPICKWEIGHTED_H
#define RANDOMPICKWEIGHTED_H

#include <random>
#include <vector>

class RandomPickWeighted
{
public:
    RandomPickWeighted(std::vector<int>& w);
    int pickIndex();

private:
    std::vector<int> prefix;
};
#endif