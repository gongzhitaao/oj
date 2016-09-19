class Solution
{
 public:
  int numDistinct(string s, string t)
  {
    int n = s.size(), m = t.size();
    vector<vector<int> > d(m + 1, vector<int>(n + 1, 0));
    fill(d[0].begin(), d[0].end(), 1);
    for (int i = 1; i <= m; ++i) {
      for (int j = i; j <= n; ++j) {
        d[i][j] += d[i][j - 1];
        if (t[i - 1] == s[j - 1]) d[i][j] += d[i - 1][j - 1];
      }
    }
    return d[m][n];
  }
};
