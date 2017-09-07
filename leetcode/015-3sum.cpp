class Solution
{
 public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int sum = -nums[i];
      for (int j = i + 1, k = n - 1, b, c; j < k;) {
        if (nums[j] + nums[k] < sum) ++j;
        else if (nums[j] + nums[k] > sum) --k;
        else {
          ret.push_back({nums[i], nums[j], nums[k]});
          for (++j; j > i + 1 && j < k && nums[j] == nums[j - 1]; ++j);
          for (--k; k < n - 1 && k > j && nums[k] == nums[k + 1]; --k);
        }
      }
    }
    return ret;
  }
};
