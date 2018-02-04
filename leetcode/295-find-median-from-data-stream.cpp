class MedianFinder
{
  priority_queue<int> maxq_;
  priority_queue<int, vector<int>, greater<int>> minq_;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num)
  {
    if (maxq_.empty() || num <= maxq_.top())
      maxq_.push(num);
    else
      minq_.push(num);

    int s0 = maxq_.size(), s1 = minq_.size();
    if (s0 < s1 - 1) {
      maxq_.push(minq_.top());
      minq_.pop();
    } else if (s0 > s1 + 1) {
      minq_.push(maxq_.top());
      maxq_.pop();
    }
  }

  double findMedian()
  {
    if (maxq_.size() == minq_.size() && !maxq_.empty())
      return (maxq_.top() + minq_.top()) / 2.0;
    if (maxq_.size() > minq_.size()) return maxq_.top();
    return minq_.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
