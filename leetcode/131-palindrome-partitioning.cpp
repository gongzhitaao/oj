class Solution
{
 public:
  vector<vector<string>> partition(string s)
  {
    if (s.empty()) return {{}};
    const int n = s.size();

    vector<vector<int>> pal(n, vector<int>());
    pal[0].push_back(0);

    vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>());
    dp[0].push_back(vector<string>());
    dp[1].push_back(vector<string>{s.substr(0, 1)});

    for (int i = 1; i < n; ++i) {
      auto& cur = dp[i + 1];

      pal[i].push_back(i);
      for (auto elm : dp[i]) {
        elm.push_back(s.substr(i, 1));
        cur.push_back(elm);
      }

      if (s[i] == s[i - 1]) {
        pal[i].push_back(i - 1);
        for (auto elm : dp[i - 1]) {
          elm.push_back(s.substr(i - 1, 2));
          cur.push_back(elm);
        }
      }

      for (int j = 0; j < pal[i - 1].size(); ++j) {
        int k = pal[i - 1][j] - 1;
        if (k >= 0 && s[i] == s[k]) {
          pal[i].push_back(k);
          for (auto elm : dp[k]) {
            elm.push_back(s.substr(k, i - k + 1));
            cur.push_back(elm);
          }
        }
      }
    }

    return dp.back();
  }
};
