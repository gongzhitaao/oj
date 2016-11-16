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
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](Interval& a, Interval& b) {
           return a.start < b.start; });
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(0);
    for (Interval& itv : intervals) {
      int e = q.top();
      if (itv.start >= e) q.pop();
      q.push(itv.end);
    }
    return q.size();
  }
};
