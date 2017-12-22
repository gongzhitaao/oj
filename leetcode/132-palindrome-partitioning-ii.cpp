class Solution
{
 public:
  int minCut(string s)
  {
    if (s.empty() || s.size() == 1) return 0;

    const int n = s.size();
    vector<int> cnt(n + 1, -1);
    vector<vector<int>> pal(n + 1, vector<int>());

    for (int i = 0; i < n; ++i) {
      pal[i + 1].push_back(i);
      cnt[i + 1] = 1 + cnt[i];

      if (i > 0 && s[i] == s[i - 1]) {
        pal[i + 1].push_back(i - 1);
        if (cnt[i - 1] + 1 < cnt[i + 1]) cnt[i + 1] = 1 + cnt[i - 1];
      }

      for (int j = 0; j < pal[i].size(); ++j) {
        int k = pal[i][j] - 1;
        if (k >= 0 && s[k] == s[i]) {
          pal[i + 1].push_back(k);
          if (cnt[k] + 1 < cnt[i + 1]) cnt[i + 1] = cnt[k] + 1;
        }
      }
    }

    return cnt[n];
  }
};
