class Solution
{
 public:
  int numTrees(int n)
  {
    vector<int> cnt(n+1, 0);
    cnt[0] = cnt[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j)
        cnt[i] += cnt[j-1] * cnt[i-j];
    }
    return cnt[n];
  }
};
