class Solution
{
 public:
  bool canWin(string s) { return dfs(s, 0); }

  bool dfs(string& s, int player)
  {
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
      if ('+' == s[i] && s[i] == s[i + 1]) {
        s[i] = s[i + 1] = '-';
        bool lost = dfs(s, 1 - player);
        s[i] = s[i + 1] = '+';
        if (!lost) return true;
      }
    }
    return false;
  }
};
