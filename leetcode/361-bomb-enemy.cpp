class Solution
{
 public:
  int maxKilledEnemies(vector<vector<char>>& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;

    int nrow = grid.size();
    int ncol = grid[0].size();

    vector<vector<int>> vert(nrow, vector<int>(ncol, 0));
    vector<vector<int>> hori(nrow, vector<int>(ncol, 0));

    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        if ('0' != grid[i][j]) continue;
        bool skip = false;

        for (int ii = i-1; ii >= 0; --ii) {
          if ('W' == grid[ii][j]) break;
          if ('0' == grid[ii][j]) {
            vert[i][j] = vert[ii][j];
            skip = true;
            break;
          }
          ++vert[i][j];
        }
        if (!skip) {
          for (int ii = i+1; ii < nrow; ++ii) {
            if ('W' == grid[ii][j]) break;
            if ('E' == grid[ii][j]) ++vert[i][j];
          }
        }

        skip = false;

        for (int jj = j-1; jj >= 0; --jj) {
          if ('W' == grid[i][jj]) break;
          if ('0' == grid[i][jj]) {
            hori[i][j] = hori[i][jj];
            skip = true;
            break;
          }
          ++hori[i][j];
        }

        if (!skip) {
          for (int jj = j+1; jj < ncol; ++jj) {
            if ('W' == grid[i][jj]) break;
            if ('E' == grid[i][jj]) ++hori[i][j];
          }
        }
      }
    }

    int ret = 0;
    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (vert[i][j]+hori[i][j] > ret)
          ret = vert[i][j] + hori[i][j];

    return ret;
  }
};
