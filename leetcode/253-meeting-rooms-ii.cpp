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
    auto cmp = [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    };

    sort(intervals.begin(), intervals.end(), cmp);

    int maxcnt = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (Interval& itv : intervals) {
      for (; q.size() && itv.start >= q.top(); q.pop())
        ;
      q.push(itv.end);
      if (q.size() > maxcnt) maxcnt = q.size();
    }

    return maxcnt;
  }
};
