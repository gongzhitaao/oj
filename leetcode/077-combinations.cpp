class Solution
{
 public:
  vector<vector<int>> combine(int n, int k) { return dfs(n, k); }

  vector<vector<int>> dfs(int n, int k)
  {
    vector<vector<int>> ret;
    if (k < 1 || n < 1 || k > n) return ret;
    vector<vector<int>> a = dfs(n - 1, k);
    vector<vector<int>> b = dfs(n - 1, k - 1);
    if (b.empty())
      b = {{n}};
    else
      for (auto& v : b) v.push_back(n);
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};
