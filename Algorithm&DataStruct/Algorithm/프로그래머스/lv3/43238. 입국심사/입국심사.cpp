#include <vector>
#include <algorithm>

using namespace std;
 
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long answer = 0;
    long long min_time = 1;
    long long max_time = times.back() * static_cast<long long>(n);
    while (min_time <= max_time)
    {
        long long human = 0;
        auto mid_time = ((max_time + min_time) / 2);
        for (const auto& t : times)
        {
            auto value = mid_time / t;
            human += value;
        }
        if (n <= human)
        {
            answer = mid_time;
            max_time = mid_time - 1;
        }
        else
        {
            min_time = mid_time + 1;
        }
    }
    return answer;
}