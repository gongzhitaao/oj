class Solution {
 public:
  Solution(vector<int> nums) {
    nums_ = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return nums_;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> nums(nums_);
    mt19937 gen(rd_());
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      uniform_int_distribution<> dis(i, n - 1);
      int j = dis(gen);
      if (j != i) swap(nums[i], nums[j]);
    }
    return nums;
  }

 private:
  vector<int> nums_;
  random_device rd_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
