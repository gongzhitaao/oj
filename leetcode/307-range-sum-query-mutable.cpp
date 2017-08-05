class NumArray
{
 public:
  NumArray(vector<int> nums)
  {
    int n = nums.size();
    bit_ = vector<int>(n+1, 0);
    for (int i = 0; i < n; ++i)
      update(i, nums[i]);
  }

  void update(int i, int val)
  {
    int diff = val - sumRange(i, i);
    for (int j = i + 1; j < bit_.size(); j += j & -j)
      bit_[j] += diff;
  }

  int sumRange(int i, int j)
  {
    return query(j+1) - query(i);
  }

 private:
  int query(int i)
  {
    int sum = 0;
    for (; i > 0; i -= i & -i)
      sum += bit_[i];
    return sum;
  }

  vector<int> bit_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
