class Solution
{
 public:
  bool canPartition(vector<int>& nums)
  {
    int sum = 0;
    for (int n : nums) sum += n;
    if (sum & 1) return false;
    sum /= 2;

    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for (int n : nums) {
      for (int i = sum; i >= n; --i)
        dp[i] = dp[i] || dp[i-n];
      if (dp[sum]) return true;
    }

    return false;
  }
};
