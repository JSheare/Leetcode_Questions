#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "DisjointSet.h"

// Solved this one using union find as opposed to some kind of graph setup. See DisjointSet.h for implementation

std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts)
{
    // Linking emails with account ids using union
    DisjointSet<int> ds;
    std::unordered_map<std::string, int> emailToId;
    for (int i{ 0 }; i < accounts.size(); ++i)
    {
        ds.addSet(i);
        for (int j{ 1 }; j < accounts[i].size(); ++j)
        {
            if (emailToId.count(accounts[i][j]))
                ds.unionSets(i, emailToId[accounts[i][j]]);
            else
                emailToId[accounts[i][j]] = i;
        }
    }

    // Making arrays of emails for each id using find
    std::unordered_map<int, std::vector<std::string>> groupById;
    for (auto& pair : emailToId)
    {
        groupById[ds.find(emailToId[pair.first])].push_back(pair.first);
    }

    // Sorting the emails 
    std::vector<std::vector<std::string>> result;
    for (auto& pair : groupById)
    {
        std::vector<std::string> data{ accounts[pair.first][0] };
        std::vector<std::string>& emails{ pair.second };
        std::sort(emails.begin(), emails.end());
        for (auto& email : emails)
        {
            data.push_back(email);
        }
        result.push_back(data);
    }
    return result;
}

# if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<std::string>> test1{
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    std::vector<std::vector<std::string>> correct1{
        {"John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    std::vector<std::vector<std::string>> answer1{ accountsMerge(test1) };
    assert(answer1 == correct1);

    std::vector<std::vector<std::string>> test2{
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
    };
    std::vector<std::vector<std::string>> correct2{
        {"Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"},
        {"Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"},
        {"Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"},
        {"Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"},
        {"Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"}
    };
    std::vector<std::vector<std::string>> answer2{ accountsMerge(test2) };
    assert(answer2 == correct2);

    std::cout << "Success!\n";

    return 0;
}
#endif