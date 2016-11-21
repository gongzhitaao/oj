class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    vector<char> cands;
    for (int i = 0; i < p.size(); ++i) {
      if (i+1 < p.size() && '*' == p[i+1])
        cands.push_back(-p[i++]);
      else cands.push_back(p[i]);
    }
    int ns = s.size(), np = cands.size();

    vector<vector<bool> > dp(ns+1, vector<bool>(np+1, false));
    dp[0][0] = true;
    for (int i = 0; i <= ns; ++i) {
      for (int j = 1; j <= np; ++j) {
        if (cands[j-1] < 0) {
          if (dp[i][j] = dp[i][j-1]) continue;
          if ('.' == -cands[j-1] || s[i-1] == -cands[j-1]) {
            for (int k = i-1;
                 k >= 0 && ('.' == -cands[j-1] ||
                            s[k] == -cands[j-1]);
                 --k)
              if (dp[i][j] = dp[k][j-1]) break;
          }
        } else {
          dp[i][j] = ('.' == cands[j-1] || s[i-1] == cands[j-1]) &&
                     (i > 0 && dp[i-1][j-1]);
        }
      }
    }
    return dp[ns][np];
  }
};
