class Solution
{
 public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<vector<int>> ret;
    vector<int> tmp;
    dfs(1, tmp, k, n, ret);
    return ret;
  }

  void dfs(int start, vector<int> &tmp, int k, int n, vector<vector<int>> &ret)
  {
    if (k <= 1) {
      if (start <= n && n <= 9) {
        tmp.push_back(n);
        ret.push_back(tmp);
        tmp.pop_back();
      }
      return;
    }

    if (start >= n) return;

    for (int i = start; i <= 10-k; ++i) {
      tmp.push_back(i);
      dfs(i+1, tmp, k-1, n-i, ret);
      tmp.pop_back();
    }
  }
};
