class Solution
{
 public:
  int minPathSum(vector<vector<int>>& grid)
  {
    const int row = grid.size(), col = grid[0].size();
    vector<int> d(col + 1, numeric_limits<int>::max());
    d[1] = 0;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        d[j + 1] = min(d[j], d[j + 1]) + grid[i][j];
    return d[col];
  }
};
