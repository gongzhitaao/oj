class Solution
{
  vector<int> nums_;
 public:
  Solution(vector<int> nums) : nums_(nums) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset()
  {
    return nums_;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle()
  {
    vector<int> ret = nums_;
    for (int i = 0; i < ret.size(); ++i) {
      int j = rand() % (ret.size() - i) + i;
      if (i != j) swap(ret[i], ret[j]);
    }
    return ret;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
