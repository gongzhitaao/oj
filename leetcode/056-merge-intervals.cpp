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
  vector<Interval> merge(vector<Interval>& intervals)
  {
    vector<Interval> ret;
    if (intervals.empty()) return ret;

    auto cmp = [](const Interval& a, const Interval& b) {
      return a.start < b.start || a.start == b.start && a.end > b.end;
    };

    sort(intervals.begin(), intervals.end(), cmp);

    Interval itv = intervals[0];
    for (int i = 1, last = itv.start; i < intervals.size(); ++i) {
      Interval& cur = intervals[i];
      if (cur.start == last) continue;
      if (cur.start > itv.end) {
        ret.push_back(itv);
        itv = cur;
      } else
        itv.end = max(itv.end, cur.end);
    }
    ret.push_back(itv);

    return ret;
  }
};
