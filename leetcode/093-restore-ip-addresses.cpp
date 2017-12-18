class Solution
{
 public:
  vector<string> restoreIpAddresses(string s)
  {
    vector<string> ret;
    if (s.size() <= 12) dfs(s, 0, 4, ret, "");
    return ret;
  }

  void dfs(string& s, int i0, int n, vector<string>& ret, string cur)
  {
    if (0 == n && i0 >= s.size()) return ret.push_back(cur);

    if (n < 4) cur += ".";
    if ('0' == s[i0]) return dfs(s, i0 + 1, n - 1, ret, cur + "0");

    for (int i = i0; i < s.size(); ++i) {
      string tmp = s.substr(i0, i - i0 + 1);
      int k = stoi(tmp);
      if (k > 255) break;
      dfs(s, i + 1, n - 1, ret, cur + tmp);
    }
  }
};
