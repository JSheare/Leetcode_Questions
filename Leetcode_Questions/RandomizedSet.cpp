#include <unordered_map>
#include <vector>

#include "RandomizedSet.h"

bool RandomizedSet::insert(int val)
{
    if (mp.contains(val))
        return false;

    vals.push_back(val);
    mp[val] = static_cast<int>(vals.size() - 1);
    return true;
}

bool RandomizedSet::remove(int val)
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

int RandomizedSet::getRandom()
{
    return vals[rand() % vals.size()];
}