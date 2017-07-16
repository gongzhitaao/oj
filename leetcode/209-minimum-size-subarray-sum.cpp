class Solution
{
 public:
  int minSubArrayLen(int s, vector<int>& nums)
  {
    int n = nums.size();
    int sum = 0, ret = n + 1;
    for (int i = 0, j = 0; i < n; ) {
      for (; sum < s && i < n; ++i)
        sum += nums[i];
      if (sum < s) break;
      for (; sum >= s && j < i; ++j)
        sum -= nums[j];
      if (i-j+1 < ret)
        ret = i - j + 1;
    }
    return ret > n ? 0 : ret;
  }
};
