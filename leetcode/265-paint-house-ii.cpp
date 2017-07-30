class Solution
{
 public:
  int minCostII(vector<vector<int>>& costs)
  {
    if (costs.empty() || costs[0].empty()) return 0;

    const int row = costs.size(), col = costs[0].size();
    vector<int> dp(col, 0);

    pair<int, int> m0{0, 0}, m1{1, 0};
    for (int i = 0; i < row; ++i) {
      pair<int, int> t0{0, numeric_limits<int>::max()},
          t1{0, numeric_limits<int>::max()};
      for (int j = 0; j < col; ++j) {
        dp[j] = costs[i][j] +
            (j == m0.first ? m1.second : m0.second);
        if (dp[j] < t0.second)
          t1 = t0, t0 = {j, dp[j]};
        else if (dp[j] < t1.second)
          t1 = {j, dp[j]};
      }
      m0 = t0, m1 = t1;
    }
    return m0.second;
  }
};
