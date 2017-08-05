class NumArray
{
 public:
  NumArray(vector<int> nums)
  {
    int n = nums.size();
    st_.resize(2*n);

    for (int i = 0; i < n; ++i)
      st_[i+n] = nums[i];
    for (int i = n-1; i > 0; --i)
      st_[i] = st_[i*2] + st_[i*2+1];
  }

  void update(int i, int val)
  {
    int n = st_.size() / 2;
    i += n;

    st_[i] = val;
    while (i /= 2)
      st_[i] = st_[i*2] + st_[i*2+1];
  }

  int sumRange(int i, int j)
  {
    int n = st_.size() / 2;
    int sum = 0;
    for (i += n, j += n; i <= j; i /= 2, j /= 2) {
      if (i%2) sum += st_[i++];
      if (j%2 == 0) sum += st_[j--];
    }
    return sum;
  }

  vector<int> st_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
