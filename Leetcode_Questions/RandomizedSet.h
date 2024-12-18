#ifndef RANDOMIZEDSET_H
#define RANDOMIZEDSET_H

#include <unordered_map>
#include <vector>

class RandomizedSet {
public:
    RandomizedSet()
    {}

    bool insert(int val)
    {
        if (mp.contains(val))
            return false;

        vals.push_back(val);
        mp[val] = static_cast<int>(vals.size() - 1);
        return true;
    }

    bool remove(int val)
    {
        if (mp.contains(val))
        {
            vals[mp[val]] = vals.back();
            mp[vals.back()] = mp[val];
            vals.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return vals[rand() % vals.size()];
    }

private:
    std::unordered_map<int, int> mp;
    std::vector<int> vals;
};
#endif