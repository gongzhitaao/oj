class Solution
{
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
  {
    vector<int> cnt(101, 0);
    cnt[1] = 1;
    const int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    for (int i = 1; i <= row; ++i) {
      for (int j = 1; j <= col; ++j)
        if (!obstacleGrid[i - 1][j - 1])
          cnt[j] += cnt[j - 1];
        else
          cnt[j] = 0;
    }
    return cnt[col];
  }
};
