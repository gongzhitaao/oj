class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2)
  {
    buf_.push_back(v1);
    buf_.push_back(v2);
    ptr_ = vector<int>(buf_.size(), 0);
    cur_ = 0;
    left_ = buf_.size();
  }

  int next()
  {
    int item = buf_[cur_][ptr_[cur_]++];
    cur_ = (cur_ + 1) % buf_.size();
    return item;
  }

  bool hasNext()
  {
    for (; left_ > 0 && ptr_[cur_] >= buf_[cur_].size();
         cur_ = (cur_ + 1) % buf_.size()) {
      if (ptr_[cur_] == buf_[cur_].size()) {
        ++ptr_[cur_];
        --left_;
      }
    }
    return left_ > 0;
  }

 private:
  vector<vector<int> > buf_;
  vector<int> ptr_;
  int cur_;
  int left_;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
