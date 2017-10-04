class Solution
{
 public:
  int numIslands(vector<vector<char>>& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;

    const int row = grid.size(), col = grid[0].size();
    int cur = 0, total = row * col;
    int cnt = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if ('1' == grid[i][j]) {
          ++cnt;
          cur += dfs(grid, i, j);
          if (cur == total) return cnt;
        }
      }
    }

    return cnt;
  }

  int dfs(vector<vector<char>>& grid, int i, int j)
  {
    grid[i][j] = 'x';
    int n = 1;
    if (i > 0 && '1' == grid[i - 1][j]) n += dfs(grid, i - 1, j);
    if (j + 1 < grid[0].size() && '1' == grid[i][j + 1])
      n += dfs(grid, i, j + 1);
    if (i + 1 < grid.size() && '1' == grid[i + 1][j]) n += dfs(grid, i + 1, j);
    if (j > 0 && '1' == grid[i][j - 1]) n += dfs(grid, i, j - 1);
    return n;
  }
};
