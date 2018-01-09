class Solution
{
 public:
  int rob(vector<int>& nums)
  {
    if (nums.empty()) return 0;
    if (1 == nums.size()) return nums[0];

    int even[2] = {0, 0}, odd[2] = {0, 0};
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (i & 1) {
        odd[0] = max(even[0], odd[0] + nums[i]);
        even[1] = max(even[1] + nums[i + 1], odd[1]);
      } else {
        odd[1] = max(even[1], odd[1] + nums[i + 1]);
        even[0] = max(even[0] + nums[i], odd[0]);
      }
    }
    return max(max(odd[0], even[0]), max(odd[1], even[1]));
  }
};
