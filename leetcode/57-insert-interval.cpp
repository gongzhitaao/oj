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

    if (intervals.empty()) {
      ret.push_back(newInterval);
      return ret;
    }

    int start;
    int merging = -1;
    for (int i = 0; i < intervals.size(); ++i) {
      Interval& interval = intervals[i];
      switch (merging) {
        case -1:
          if (newInterval.end < interval.start) {
            merging = 1;
            ret.push_back(newInterval);
            ret.push_back(interval);
          } else if (newInterval.end <= interval.end) {
            merging = 1;
            start = min(interval.start, newInterval.start);
            ret.push_back(Interval(start, interval.end));
          } else if (newInterval.start <= interval.end) {
            merging = 0;
            start = min(interval.start, newInterval.start);
          } else {
            ret.push_back(interval);
          }
          break;
        case 0:
          if (newInterval.end < interval.start) {
            merging = 1;
            ret.push_back(Interval(start, newInterval.end));
            ret.push_back(interval);
          } else if (newInterval.end <= interval.end) {
            merging = 1;
            ret.push_back(Interval(start, interval.end));
          }
          break;
        case 1:
          ret.push_back(interval);
          break;
        default: /* empty */
          break;
      }
    }

    if (-1 == merging)
      ret.push_back(newInterval);
    else if (0 == merging)
      ret.push_back(Interval(start, newInterval.end));

    return ret;
  }
};
