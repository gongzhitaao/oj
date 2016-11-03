class MedianFinder
{
 public:

  // Adds a number into the data structure.
  void addNum(int num)
  {
    buf_.insert(num);
    int n = buf_.size();
    if (1 == n) {
      med_ = buf_.begin();
    } else {
      if (num < *med_) {
        if (!(n & 1)) --med_;
      } else if (num >= *med_) {
        if (n & 1) ++med_;
      }
    }
  }

  // Returns the median of current data stream
  double findMedian()
  {
    return buf_.size() & 1
        ? *med_
        : (*med_ + *next(med_)) / 2.0;
  }

 private:
  multiset<int> buf_;
  multiset<int>::iterator med_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
