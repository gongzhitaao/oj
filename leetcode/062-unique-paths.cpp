class Solution
{
 public:
  int uniquePaths(int m, int n)
  {
    vector<int> cnt(101, 0);
    cnt[1] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        cnt[j] += cnt[j-1];
    return cnt[n];
  }
};
