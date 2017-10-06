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
  bool canAttendMeetings(vector<Interval>& intervals)
  {
    auto cmp = [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    };

    sort(intervals.begin(), intervals.end(), cmp);

    for (int i = 1; i < intervals.size(); ++i) {
      Interval& a = intervals[i - 1];
      Interval& b = intervals[i];
      if (a.end > b.start) return false;
    }

    return true;
  }
};
