class Solution
{
 public:
  string alienOrder(vector<string>& words)
  {
    if (words.empty()) return "";

    vector<vector<int> > g(26, vector<int>(26, -1));

    string pre = words[0];
    for (char c : pre) g[c-'a'][c-'a'] = 0;

    int n = words.size();
    for (int i = 1; i < n; ++i) {
      string cur = words[i];
      int j, n1 = pre.size(), n2 = cur.size();
      bool match = true;
      for (j = 0; j < n1 && j < n2; ++j) {
        g[cur[j]-'a'][cur[j]-'a'] = 0;
        if (pre[j] != cur[j]) {
          if (!g[pre[j]-'a'][cur[j]-'a']) return "";
          g[cur[j]-'a'][pre[j]-'a'] = 0;
          match = false;
          break;
        }
      }
      if (match && j < n1) return "";
      for (; j < n2; ++j) g[cur[j]-'a'][cur[j]-'a'] = 0;
      pre = cur;
    }

    string ret;
    for (int i = 0, v = 0; i < 26; ++i)
      if (0 == g[i][i] && dfs(g, i, ret, ++v)) return "";
    return ret;
  }

  bool dfs(vector<vector<int> >& g, int ch, string& ret, int v)
  {
    g[ch][ch] = v;
    for (int i = 0; i < 26; ++i) {
      if (g[ch][i] < 0 || i == ch) continue;
      if (g[i][i] == v ||
          !g[i][i] && dfs(g, i, ret, v)) return true;
    }
    ret += char(ch + 'a');
    return false;
  }
};
