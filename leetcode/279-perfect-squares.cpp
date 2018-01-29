class Solution
{
 public:
  int numSquares(int n)
  {
    int sqrtn = sqrt(n);
    if (sqrtn * sqrtn == n) return 1;

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= sqrtn; ++i)
      cnt[i * i] = 1;

    for (int i = 2; i <= n; ++i) {
      if (1 == cnt[i]) continue;
      cnt[i] = i;
      for (int j = 1, end = sqrt(i); j <= end; ++j) {
        int k = j * j;
        if (cnt[k] + cnt[i - k] < cnt[i])
          cnt[i] = cnt[k] + cnt[i - k];
      }
    }

    return cnt[n];
  }
};
