class Solution
{
 public:
  int nthUglyNumber(int n)
  {
    vector<int> ugly(n + 1, numeric_limits<int>::max());
    vector<int> primes{2, 3, 5};
    vector<int> ind(3, 1);
    ugly[1] = 1;
    for (int i = 2, minj, minv; i <= n; ++i) {
      minv = numeric_limits<int>::max();
      for (int j = 0; j < 3; ++j) {
        int cur = primes[j] * ugly[ind[j]];
        if (cur < minv) minj = j, minv = cur;
      }
      ++ind[minj];
      ugly[i] = minv;
      for (int j = 0; j < 3; ++j)
        if (primes[j] * ugly[ind[j]] == ugly[i]) ++ind[j];
    }
    return ugly[n];
  }
};
