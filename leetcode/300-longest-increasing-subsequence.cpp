class Solution
{
 public:
  int lengthOfLIS(vector<int>& nums)
  {
    if (nums.empty()) return 0;

    vector<int> lis{nums[0]};
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > lis.back())
        lis.push_back(nums[i]);
      else if (nums[i] < lis.back()) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        *it = nums[i];
      }
    }

    return lis.size();
  }
};
