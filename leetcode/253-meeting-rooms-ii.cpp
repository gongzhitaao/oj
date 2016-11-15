/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
 public:
  int minMeetingRooms(vector<Interval>& intervals)
  {
    map<int, int> cnt;
    for (Interval& itv : intervals) {
      ++cnt[itv.start];
      --cnt[itv.end];
    }
    int ret = 0, n = 0;
    for (auto& e : cnt) {
      n += e.second;
      if (n > ret) ret = n;
    }
    return ret;
  }
};
