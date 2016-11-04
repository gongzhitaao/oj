class RandomizedSet {
 public:
  /** Initialize your data structure here. */
  RandomizedSet()
  {
  }

  /** Inserts a value to the set. Returns true if the set did not
   * already contain the specified element. */
  bool insert(int val)
  {
    if (pos_.find(val) != pos_.end())
      return false;
    buf_.push_back(val);
    pos_[val] = buf_.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained
   * the specified element. */
  bool remove(int val)
  {
    if (pos_.find(val) == pos_.end())
      return false;
    int p = pos_[val];
    int v = buf_.back();
    pos_[v] = p;
    buf_[p] = v;
    pos_.erase(val);
    buf_.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom()
  {
    return buf_[rand() % buf_.size()];
  }

 private:
  vector<int> buf_;
  unordered_map<int, int> pos_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
