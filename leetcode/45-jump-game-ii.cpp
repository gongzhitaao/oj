class Solution {
 public:
  int jump(vector<int>& nums)
  {
    int step = 0;
    for (int a = 0, b = 1, c = 0; b < nums.size(); ++step) {
      for (int i = a; i < b; ++i) {
        c = max(nums[i] + i + 1, c);
        if (c >= nums.size()) break;
      }
      a = b, b = c;
    }
    return step;
  }
};
