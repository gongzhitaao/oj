class Solution
{
 public:
  int findLengthOfLCIS(vector<int>& nums)
  {
    if (nums.empty()) return 0;
    int maxlen = 1, cur = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] < nums[i])
        ++cur;
      else {
        if (cur > maxlen) maxlen = cur;
        cur = 1;
      }
    }
    if (cur > maxlen) maxlen = cur;
    return maxlen;
  }
};
