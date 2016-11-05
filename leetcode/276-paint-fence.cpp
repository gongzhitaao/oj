class Solution
{
 public:
  int numWays(int n, int k)
  {
    if (0 == n) return 0;
    vector<int> v(n+1, 0);
    v[1] = k, v[2] = k*k, v[3] = k*k*k - k;
    for (int i = 4; i <= n; ++i)
      v[i] = v[i-1]*k - v[i-3]*(k-1);
    return v[n];
  }
};
