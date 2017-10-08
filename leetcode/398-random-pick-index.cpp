class Solution
{
  vector<int> nums_;
  mt19937 gen_;
  uniform_real_distribution<> dis_;

 public:
  Solution(vector<int> nums)
  {
    nums_ = nums;
    random_device rd;
    gen_ = mt19937(rd());
    dis_ = uniform_real_distribution<>(0, 1);
  }

  int pick(int target)
  {
    int p;
    for (p = 0; p < nums_.size() && nums_[p] != target; ++p)
      ;

    int cnt = 1, pos;
    for (pos = p++; p < nums_.size(); ++p) {
      if (nums_[p] == target && dis_(gen_) < (1. / ++cnt))
        pos = p;
    }

    return pos;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
