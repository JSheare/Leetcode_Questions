#ifndef RANDOMIZEDSET_H
#define RANDOMIZEDSET_H

#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
    RandomizedSet() {}
    bool insert(int val);
    bool remove(int val);
    int getRandom();

private:
    std::unordered_map<int, int> mp;
    std::vector<int> vals;
};
#endif