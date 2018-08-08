#include <bits/stdc++.h>
using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return vector<Interval>{};
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (ret.back().end < intervals[i].start)
                ret.push_back(intervals[i]);
            else
                ret.back().end = max(ret.back().end, intervals[i].end);
        }
        return ret;
    }
};