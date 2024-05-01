#ifndef TIMEMAP_H
#define TIMEMAP_H

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

class TimeMap
{
private:
	std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

public:
	TimeMap()
	{}

	void set(std::string key, std::string value, int timestamp)
	{
		mp[key].push_back({ timestamp, value });
	}

	std::string get(std::string key, int timestamp)
	{
        if (mp.count(key) == 0)
            return "";

        std::vector<std::pair<int, std::string>>& vals{ mp[key] };
        if (vals[0].first > timestamp)
            return "";

        int low{ 0 };
        int high{ static_cast<int>(mp[key].size()) - 1 };
        while (low < high)
        {
            int mid{ low + (high - low + 1) / 2 };
            if (vals[mid].first > timestamp)
                high = mid - 1;
            else
            {
                low = mid;
            }
        }
        return vals[low].second;
	}
};
#endif
