class Solution
{
 public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());

    const int n = nums.size();
    vector<vector<int>> ret;

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int sum = nums[i];
      for (int j = i + 1, k = n - 1; j < k;) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          ++j;
          continue;
        }

        if (k < n - 1 && nums[k] == nums[k + 1]) {
          --k;
          continue;
        }

        if (nums[j] + nums[k] + sum > 0)
          --k;
        else if (nums[j] + nums[k] + sum < 0)
          ++j;
        else
          ret.push_back({nums[i], nums[j++], nums[k--]});
      }
    }

    return ret;
  }
};
