class Solution {
 public:
  void dfs(string s, char ch, int start)
  {
    for (int i = max(0, start - 1), cnt = 0; i < s.size(); ++i) {
      if ('(' == s[i] || ')' == s[i])
        s[i] == ch ? ++cnt : --cnt;
      if (cnt <= 0) continue;
      for (int j = start; j <= i; ++j) {
        if (s[j] == ch && (j == start || s[j - 1] != ch))
          dfs(s.substr(0, j) + s.substr(j + 1), ch, j);
      }
      return;
    }

    reverse(s.begin(), s.end());
    if (')' == ch) dfs(s, '(', 0);
    else ret.push_back(s);
  }

  vector<string> removeInvalidParentheses(string s)
  {
    dfs(s, ')', 0);
    return ret;
  }

 private:
  vector<string> ret;
};
