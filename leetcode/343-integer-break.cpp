class Solution
{
 public:
  int integerBreak(int n)
  {
    vector<int> res(60, 0);
    res[1] = res[2] = 1;
    return dp(n, res);
  }

  int dp(int n, vector<int>& res)
  {
    if (res[n] > 0) return res[n];
    for (int i = 1; i <= n / 2; ++i)
      res[n] = max(max(i, dp(i, res)) * max(n - i, dp(n - i, res)), res[n]);
    return res[n];
  }
};
