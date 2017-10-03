class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    return dfs(s, p, 0, 0, 0);
  }

  bool dfs(const string& s, const string& p, int i0, int j0, char last)
  {
    if (s.size() == i0) {
      if (p.size() == j0)
        return true;
      if (j0 + 1 == p.size())
        return false;
      return '*' == p[j0 + 1] && dfs(s, p, i0, j0 + 2, p[j0]);
    }

    if (p.size() == j0)
      return '.' == last || (last == s[i0] && dfs(s, p, i0 + 1, j0, last));

    if (last)
      return dfs(s, p, i0, j0, 0) ||
             (('.' == last || last == s[i0]) && dfs(s, p, i0 + 1, j0, last));

    if (j0 + 1 < p.size() && '*' == p[j0 + 1])
      return dfs(s, p, i0, j0 + 2, 0) ||
             ('.' == p[j0] || s[i0] == p[j0]) &&
               dfs(s, p, i0 + 1, j0 + 2, p[j0]);

    return ('.' == p[j0] || s[i0] == p[j0]) && dfs(s, p, i0 + 1, j0 + 1, 0);
  }
};
