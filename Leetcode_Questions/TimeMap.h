#ifndef TIMEMAP_H
#define TIMEMAP_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class TimeMap
{
public:
	TimeMap() {}
    void set(std::string key, std::string value, int timestamp);
	std::string get(std::string key, int timestamp);

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;
};
#endif
