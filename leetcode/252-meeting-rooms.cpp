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
    if (intervals.empty()) return true;

    vector<int> indices;
    for (int i = 0; i < intervals.size(); ++i)
      indices.push_back(i);
    return mergesort(intervals, indices, 0, intervals.size() - 1);
  }

  bool mergesort(const vector<Interval>& intervals, vector<int>& indices,
                 int lo, int hi)
  {
    if (lo == hi)
      return true;

    int mi = lo + (hi - lo) / 2;

    if (!mergesort(intervals, indices, lo, mi)) return false;
    if (!mergesort(intervals, indices, mi + 1, hi)) return false;

    vector<int> vec(hi - lo + 1, 0);

    int i = lo, j = mi + 1, k = 0;

    for (; i <= mi && j <= hi; ++k) {
      const Interval& a = intervals[indices[i]];
      const Interval& b = intervals[indices[j]];
      if (a.start < b.start)
        vec[k] = indices[i++];
      else if (a.start > b.start)
        vec[k] = indices[j++];
      else return false;

      if (k > 0 && intervals[vec[k - 1]].end > intervals[vec[k]].start)
        return false;
    }

    for (; i <= mi; ++i, ++k) {
      const Interval& a = intervals[indices[i]];
      vec[k] = indices[i];
      if (k > 0 && intervals[vec[k - 1]].end > intervals[vec[k]].start)
        return false;
    }

    for (; j <= hi; ++j, ++k) {
      const Interval& b = intervals[indices[j]];
      vec[k] = indices[j];
      if (k > 0 && intervals[vec[k - 1]].end > intervals[vec[k]].start)
        return false;
    }

    copy(vec.begin(), vec.end(), indices.begin() + lo);

    return true;
  }
};
