class MovingAverage
{
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size)
  {
    size_ = size;
    sum_ = 0;
  }

  double next(int val)
  {
    sum_ += val;
    buf_.push(val);
    if (buf_.size() > size_) {
      sum_ -= buf_.front();
      buf_.pop();
    }
    return double(sum_) / buf_.size();
  }

 private:
  int size_;
  int sum_;
  queue<int> buf_;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
