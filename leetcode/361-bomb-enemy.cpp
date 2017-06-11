class Solution
{
 public:
  int maxKilledEnemies(vector<vector<char>>& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;

    int nrow = grid.size();
    int ncol = grid[0].size();

    vector<vector<int>> cnt(nrow, vector<int>(ncol, 0));

    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        if ('E' != grid[i][j]) continue;

        for (int ii = i-1; ii >= 0; --ii) {
          if ('W' == grid[ii][j]) break;
          if ('0' == grid[ii][j]) ++cnt[ii][j];
        }
        for (int ii = i+1; ii < nrow; ++ii) {
          if ('W' == grid[ii][j]) break;
          if ('0' == grid[ii][j]) ++cnt[ii][j];
        }
        for (int jj = j-1; jj >= 0; --jj) {
          if ('W' == grid[i][jj]) break;
          if ('0' == grid[i][jj]) ++cnt[i][jj];
        }
        for (int jj = j+1; jj < ncol; ++jj) {
          if ('W' == grid[i][jj]) break;
          if ('0' == grid[i][jj]) ++cnt[i][jj];
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (cnt[i][j] > ret)
          ret = cnt[i][j];

    return ret;
  }
};
