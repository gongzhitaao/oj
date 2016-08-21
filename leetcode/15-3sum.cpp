class Solution {
 public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    vector<vector<int> > ret;
    int a, b, c;
    for (int i = 0; i < sz - 2; ++i) {
      if (i > 0 && nums[i] == a) continue;
      a = nums[i];

      for (int j = i + 1, k = sz - 1; j < k; /* empty */) {
        int sum = nums[i] + nums[j] + nums[k];
        if (!sum) {
          ret.push_back({nums[i], nums[j], nums[k]});
          b = nums[j];
          while (j < k && nums[j] == b) ++j;
          c = nums[k];
          while (j < k && nums[k] == c) --k;
        } else if (sum > 0) {
          c = nums[k];
          while (j < k && nums[k] == c) --k;
        } else /* if (sum < 0) */ {
          b = nums[j];
          while (j < k && nums[j] == b) ++j;
        }
      }
    }
    return ret;
  }
};
