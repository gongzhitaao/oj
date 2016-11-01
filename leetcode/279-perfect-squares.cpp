class Solution
{
 public:
  int numSquares(int n)
  {
    vector<int> cnt(n, 0);
    return dp(n, cnt);
  }

  int dp(int n, vector<int>& cnt)
  {
    if (0 >= n) return 0;
    if (1 == n) return 1;
    if (cnt[n-1] > 0) return cnt[n-1];

    int mincnt = n;
    for (int i = 2; i <= sqrt(n); ++i) {
      int cur = dp(n-i*i, cnt) + 1;
      if (cur < mincnt) mincnt = cur;
    }
    return cnt[n-1] = mincnt;
  }
};
