class MedianFinder
{
 public:

  // Adds a number into the data structure.
  void addNum(int num)
  {
    small_.push(num);
    large_.push(-small_.top());
    small_.pop();
    if (small_.size() < large_.size()) {
      small_.push(-large_.top());
      large_.pop();
    }
  }

  // Returns the median of current data stream
  double findMedian()
  {
    return small_.size() > large_.size()
        ? small_.top()
        : (small_.top() - large_.top()) / 2.0;
  }

 private:
  priority_queue<int> small_, large_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
