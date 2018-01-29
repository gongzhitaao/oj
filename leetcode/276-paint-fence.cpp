class Solution
{
 public:
  int numWays(int n, int k)
  {
    if (0 == n) return 0;
    int v0 = 0, v1 = k;
    for (int i = 1; i < n; ++i) {
      int t0 = v0;
      v0 = v1;
      v1 = (t0 + v1) * (k - 1);
    }
    return v0 + v1;
  }
};
