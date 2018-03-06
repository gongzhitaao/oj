class RandomizedCollection
{
  vector<int> buf_;
  unordered_map<int, unordered_set<int>> pos_;
  int end_;
  mt19937 gen_;

 public:
  /** Initialize your data structure here. */
  RandomizedCollection()
  {
    random_device rd;
    gen_ = mt19937(rd());
    end_ = 0;
  }

  /** Inserts a value to the collection. Returns true if the collection did not
   * already contain the specified element. */
  bool insert(int val)
  {
    bool dup = pos_.find(val) == pos_.end();
    if (end_ < buf_.size())
      buf_[end_] = val;
    else
      buf_.push_back(val);
    pos_[val].insert(end_++);
    return dup;
  }

  /** Removes a value from the collection. Returns true if the collection
   * contained the specified element. */
  bool remove(int val)
  {
    bool had = pos_.find(val) != pos_.end();
    if (had) {
      auto& removed = pos_[val];
      int p = *removed.begin();
      swap(buf_[--end_], buf_[p]);
      removed.erase(p);
      if (removed.empty()) pos_.erase(val);
      if (buf_[p] != val) {
        auto& perturbed = pos_[buf_[p]];
        perturbed.erase(end_);
        perturbed.insert(p);
      }
    }
    return had;
  }

  /** Get a random element from the collection. */
  int getRandom()
  {
    if (0 == end_) return 0;
    if (1 == end_) return *buf_.begin();
    uniform_int_distribution<> dis(0, end_ - 1);
    return *next(buf_.begin(), dis(gen_));
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
