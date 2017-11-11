class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    const int ns = s.size(), np = p.size();

    if (s.empty()) {
      for (int i = 0; i < np; ++i)
        if ('*' != p[i]) return false;
      return true;
    }

    if (p.empty()) return false;

    vector<vector<bool>> m(ns + 1, vector<bool>(np + 1, false));
    m[0][0] = true;
    for (int i = 0; i < np && '*' == p[i]; ++i)
      m[0][i + 1] = true;

    for (int i = 1; i <= ns; ++i) {
      for (int j = 1; j <= np; ++j) {
        if ('?' == p[j - 1]) {
          m[i][j] = m[i - 1][j - 1];
        } else if ('*' == p[j - 1]) {
          for (int k = 0; k <= i && !m[i][j]; ++k)
            m[i][j] = m[k][j - 1];
        } else {
          m[i][j] = s[i - 1] == p[j - 1] && m[i - 1][j - 1];
        }
      }
    }

    return m[ns][np];
  }
};
