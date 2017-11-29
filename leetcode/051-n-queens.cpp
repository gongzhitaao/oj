class Solution
{
 public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ret;
    if (n < 1) return ret;

    vector<bool> col(n, true);
    vector<bool> d0(2 * n, true), d1(2 * n, true);

    vector<string> cur(n, string(n, '.'));
    dfs(ret, 0, n, cur, col, d0, d1);

    int half = ret.size();
    for (int i = 0; i < half; ++i) {
      vector<string> elm = ret[i];
      if ('Q' == elm[0][n / 2]) continue;
      for (auto& s : elm) reverse(s.begin(), s.end());
      ret.push_back(elm);
    }

    return ret;
  }

  void dfs(vector<vector<string>>& ret, int i, int n, vector<string>& cur,
           vector<bool>& col, vector<bool>& d0, vector<bool>& d1)
  {
    if (i == n) return ret.push_back(vector<string>(cur));

    int end = 0 == i ? (n + 1) / 2 : n;
    for (int j = 0; j < end; ++j) {
      if (col[j] && d0[n - 1 - i + j] && d1[i + j]) {
        col[j] = d0[n - 1 - i + j] = d1[i + j] = false;
        cur[i][j] = 'Q';
        dfs(ret, i + 1, n, cur, col, d0, d1);
        cur[i][j] = '.';
        col[j] = d0[n - 1 - i + j] = d1[i + j] = true;
      }
    }
  }
};
