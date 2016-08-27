class Solution {
 public:
  int jump(vector<int>& nums)
  {
    int jumps = 0, a = 0, b = 0;
    for (int i = 0; i < nums.size(); ++i) {
      b = max(nums[i] + i, b);
      if (a + 1 >= nums.size()) break;
      if (i == a) a = b, ++jumps;
    }
    return jumps;
  }
};
