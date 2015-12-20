class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;

    int a = 0, b = nums[0];

    int ret = b;
    for (int i = 1; i < nums.size(); ++i) {
      ret = a + nums[i] > b ? a + nums[i] : b;
      a = b;
      b = ret;
    }

    return ret;
  }
};
