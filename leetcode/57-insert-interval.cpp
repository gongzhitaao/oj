/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals,
                          Interval newInterval)
  {
    vector<Interval> ret;
    Interval newitv = newInterval;
    bool inserted = false;
    for (Interval& itv : intervals) {
      if (inserted) ret.push_back(itv);
      else {
        if (newitv.end < itv.start) {
          inserted = true;
          ret.push_back(newitv);
          ret.push_back(itv);
        } else if (newitv.start > itv.end) {
          ret.push_back(itv);
        } else {
          newitv.start = min(newitv.start, itv.start);
          newitv.end = max(newitv.end, itv.end);
        }
      }
    }

    if (!inserted)
      ret.push_back(newitv);

    return ret;
  }
};
