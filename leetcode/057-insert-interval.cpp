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
  vector<Interval> insert(vector<Interval>& intervals, Interval itv)
  {
    if (intervals.empty()) return {itv};

    vector<Interval> ret;

    if (itv.end < intervals[0].start) {
      ret.push_back(itv);
      copy(intervals.begin(), intervals.end(), back_inserter(ret));
      return ret;
    }

    if (itv.start > intervals.back().end) {
      ret = intervals;
      ret.push_back(itv);
      return ret;
    }

    int lo, mi, hi;

    for (lo = 0, hi = intervals.size() - 1; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      Interval& cur = intervals[mi];
      if (cur.end < itv.start) lo = mi + 1;
      else hi = mi;
    }

    int p1 = lo;

    for (lo = 0, hi = intervals.size() - 1; lo < hi; ) {
      mi = lo + (hi - lo + 1) / 2;
      Interval& cur = intervals[mi];
      if (cur.start > itv.end) hi = mi - 1;
      else lo = mi;
    }

    int p2 = lo;

    for (int i = 0; i < p1; ++i)
      ret.push_back(intervals[i]);

    itv.start = min(itv.start, intervals[p1].start);
    itv.end = max(itv.end, intervals[p2].end);
    ret.push_back(itv);

    for (int i = p2 + 1; i < intervals.size(); ++i)
      ret.push_back(intervals[i]);

    return ret;
  }
};
