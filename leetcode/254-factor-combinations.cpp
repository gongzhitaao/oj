class Solution
{
 public:
  vector<vector<int>> getFactors(int n)
  {
    if (n < 4) return vector<vector<int>>();
    return factor(n, 2);
  }

  vector<vector<int>> factor(int n, int start)
  {
    if (n == start) return {{n}};

    vector<vector<int>> ret;
    for (int i = start; i <= n / 2 && i <= n / i; ++i) {
      if (n % i != 0) continue;
      ret.push_back({i, n / i});
      if (i == n / i) break;
      vector<vector<int>> cur = factor(n / i, i);
      for (vector<int>& v : cur) {
        v.push_back(i);
        ret.push_back(v);
      }
    }
    return ret;
  }
};
