#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>
#include <algorithm>


int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit)
{
    // Sorting jobs based on their end times
    std::vector<std::tuple<int, int, int>> jobs;
    for (int i{ 0 }; i < startTime.size(); ++i)
    {
        jobs.push_back({ endTime[i], startTime[i], profit[i] });
    }
    std::sort(jobs.begin(), jobs.end());

    std::vector<int> dp(jobs.size());
    std::vector<int> ends(jobs.size());
    for (int i{ 0 }; i < jobs.size(); ++i)
    {
        ends[i] = get<0>(jobs[i]);
    }
    for (int i{ 0 }; i < jobs.size(); ++i)
    {
        // Upper_bound (binary search) will return an iterator to the first job that ends after the start of the 
        // current job. One job back from this (-1) is the the most recent non-overlapping job. 
        int prevJob{ static_cast<int>(upper_bound(ends.begin(), ends.end(), get<1>(jobs[i])) - ends.begin()) - 1 };

        // If the current job has a larger potential profit than the current maximum, do the job
        // Using these ternary operators in lieu of a dummy job at the beginning of the dp arrays
        int include{ get<2>(jobs[i]) + (prevJob >= 0 ? dp[prevJob] : 0) };
        int exclude{ i > 0 ? dp[i - 1] : 0 };
        dp[i] = std::max(include, exclude);
    }
    return dp[jobs.size() - 1];
}

#if 0
int main()
{
    // Provided test cases
    std::vector<int> startTime1{ 1, 2, 3, 3 };
    std::vector<int> endTime1{ 3, 4, 5, 6 };
    std::vector<int> profit1{ 50, 10, 40, 70 };
    assert(jobScheduling(startTime1, endTime1, profit1) == 120);

    std::vector<int> startTime2{ 1, 2, 3, 4, 6 };
    std::vector<int> endTime2{ 3, 5, 10, 6, 9 };
    std::vector<int> profit2{ 20, 20, 100, 70, 60 };
    assert(jobScheduling(startTime2, endTime2, profit2) == 150);

    std::vector<int> startTime3{ 1, 1, 1 };
    std::vector<int> endTime3{ 2, 3, 4 };
    std::vector<int> profit3{ 5, 6, 4 };
    assert(jobScheduling(startTime3, endTime3, profit3) == 6);

    std::cout << "Success!\n";

    return 0;
}
#endif