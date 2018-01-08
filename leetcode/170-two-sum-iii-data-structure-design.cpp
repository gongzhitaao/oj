class TwoSum
{
  multiset<int> nums_;
 public:
  /** Initialize your data structure here. */
  TwoSum() {}

  /** Add the number to an internal data structure.. */
  void add(int number)
  {
    nums_.insert(number);
  }

  /** Find if there exists any pair of numbers which sum is equal to the value.
   */
  bool find(int value)
  {
    if (nums_.empty()) return false;

    for (auto i = nums_.begin(), j = prev(nums_.end()); i != j; ) {
      int cur = *i + *j;
      if (cur == value) return true;
      if (cur < value) ++i;
      else --j;
    }
    return false;
  }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
