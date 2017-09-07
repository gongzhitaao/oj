class Solution
{
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int t0 = target - nums[i];
      for (int a = i + 1; a < n - 2; ++a) {
        if (a > i + 1 && nums[a] == nums[a - 1]) continue;
        int t1 = t0 - nums[a];
        for (int b = a + 1, c = n - 1; b < c;) {
          if (nums[b] + nums[c] < t1) ++b;
          else if (nums[b] + nums[c] > t1) --c;
          else {
            ret.push_back({nums[i], nums[a], nums[b], nums[c]});
            for (++b; b < c && nums[b] == nums[b - 1]; ++b);
            for (--c; b < c && nums[c] == nums[c + 1]; --c);
          }
        }
      }
    }
    return ret;
  }
};
