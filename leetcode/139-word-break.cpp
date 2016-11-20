class Solution
{
 public:
  bool wordBreak(string s, unordered_set<string>& wordDict)
  {
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[i] = dp[j] &&
            wordDict.find(s.substr(j, i-j)) != wordDict.end())
          break;
      }
    }
    return dp[n];
  }
};
