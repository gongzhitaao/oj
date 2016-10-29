class Solution
{
 public:
  string decodeString(string s)
  {
    string ret;
    if (!s.empty()) ret = dfs(s);
    return ret;
  }

  string dfs(string s)
  {
    string ret;
    int size = s.size();
    for (int i = 0, j = 0, d = 0, n = 0; j < size; ++j) {
      if ('[' == s[j]) {
        if (0 == d++) i = j + 1;
      } else if (']' == s[j]) {
        if (0 == --d) {
          string tmp = dfs(s.substr(i, j-i));
          for (int k = 0; k < n; ++k) ret += tmp;
          i = j + 1;
          n = 0;
        }
      } else if (!d) {
        if (isdigit(s[j]))
          n = n * 10 + s[j] - '0';
        else
          ret += s[j];
      }
    }
    return ret;
  }
};
