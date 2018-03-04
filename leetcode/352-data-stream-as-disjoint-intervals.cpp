/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges
{
  map<int, int> intervals_;

 public:
  /** Initialize your data structure here. */
  SummaryRanges() {}

  void addNum(int val)
  {
    if (intervals_.empty()) {
      intervals_[val] = val;
      return;
    }
    auto ub = intervals_.upper_bound(val);
    if (ub == intervals_.begin()) {
      if (ub->first - 1 == val) {
        intervals_[val] = ub->second;
        intervals_.erase(ub);
      } else
        intervals_[val] = val;
    } else {
      auto p = prev(ub);
      if (ub == intervals_.end() || ub->first - 1 > val) {
        if (p->second + 1 < val)
          intervals_[val] = val;
        else if (p->second + 1 == val)
          p->second = val;
      } else {
        if (p->second + 1 < val)
          intervals_[val] = ub->second;
        else if (p->second + 1 == val)
          p->second = ub->second;
        intervals_.erase(ub);
      }
    }
  }

  vector<Interval> getIntervals()
  {
    vector<Interval> ret;
    for (auto& elm : intervals_) ret.push_back(Interval(elm.first, elm.second));
    return ret;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
