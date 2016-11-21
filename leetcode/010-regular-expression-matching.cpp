class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    return dfs(s, p);
  }

  bool dfs(string s, string p)
  {
    int ns = s.size(), np = p.size();

    if (!ns) {
      if (!np) return true;
      if (np % 2) return false;
      for (int i = 1; i < np; i += 2)
        if ('*' != p[i]) return false;
      return true;
    }

    if (!np) return false;

    int i, j;
    for (i = 0, j = 0; i < ns && j < np; ) {
      if ('.' == p[j]) {
        if (j+1 == np) return i+1 == ns;
        if ('*' == p[j+1]) {
          for (int k = ns; k >= i; --k) {
            if (dfs(s.substr(k), p.substr(j+2)))
              return true;
          }
          return false;
        }
        ++i, ++j;
      } else {
        if (j+1 == np) return i+1 == ns && s[i] == p[j];
        if ('*' == p[j+1]) {
          if (s[i] != p[j]) return dfs(s.substr(i), p.substr(j+2));
          int k;
          for (k = i + 1; k < ns && s[k] == s[i]; ++k) /* empty */;
          for (; k >= i; --k) {
            if (dfs(s.substr(k), p.substr(j+2)))
              return true;
          }
          return false;
        }
        if (s[i] != p[j]) return false;
        ++i, ++j;
      }
    }

    if (j < np) return dfs("", p.substr(j));
    return false;
  }
};
