#include "headers.hpp"

using vec2i = vector<vector<int>>;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), 
    [](const auto& a, const auto& b) {
    return a[0] < b[0];
    });

    vec2i output;
    output.reserve(intervals.size());
    output.push_back(intervals[0]);
    for(const auto& interval : intervals) {
        auto start = interval[0];
        auto end = interval[1];
        auto last_end = output.back()[1];

        if(start <= last_end) {
            auto& last_interval_ending = output.back()[1];
            last_interval_ending = max(last_end, end);
        } else {
            output.push_back({start, end});
        }
    }
    return output;
}

int main(int argc, char *argv[])
{

    return 0;
}