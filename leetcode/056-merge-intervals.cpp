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
    int n = intervals.size();
    if (!n) return ret;

    sort(intervals.begin(), intervals.end(),
         [](Interval &a, Interval &b) {
           return a.start < b.start;
         });
    Interval itv = intervals[0];
    for (int i = 1; i < n; ++i) {
      Interval &cur = intervals[i];
      if (cur.start > itv.end) {
        ret.push_back(itv);
        itv = cur;
      } else {
        itv.end = max(itv.end, cur.end);
      }
    }
    ret.push_back(itv);
    return ret;
  }
};
