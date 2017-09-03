class Solution
{
 public:
  bool find132pattern(vector<int>& nums)
  {
    const int n = nums.size();
    for (int i = 1; i < n - 1; ++i) {
      int l = nums[i];
      for (int j = 0; j < i; ++j)
        if (nums[j] < l) l = nums[j];

      if (l == nums[i]) continue;

      for (int j = i + 1; j < n; ++j)
        if (nums[j] > l && nums[j] < nums[i])
          return true;
    }
    return false;
  }
};
