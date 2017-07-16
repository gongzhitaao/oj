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
    struct {
      bool operator()(const Interval& a, const Interval& b) const
      { return a.start < b.start; }
    } comp ;

    sort(intervals.begin(), intervals.end(), comp);

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < intervals[i-1].end)
        return false;
    }

    return true;
  }
};
