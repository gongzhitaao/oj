class Solution
{
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes)
  {
    vector<int> ugly(n + 1, 1);
    vector<int> ind(primes.size(), 1);
    for (int i = 2, minj, minv; i <= n; ++i) {
      minv = numeric_limits<int>::max();
      for (int j = 0; j < primes.size(); ++j) {
        int cur = primes[j] * ugly[ind[j]];
        if (cur < minv) minv = cur, minj = j;
      }
      ++ind[minj];
      ugly[i] = minv;
      for (int j = 0; j < primes.size(); ++j)
        if (primes[j] * ugly[ind[j]] == minv) ++ind[j];
    }
    return ugly[n];
  }
};
