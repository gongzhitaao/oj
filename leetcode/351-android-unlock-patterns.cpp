class Solution
{
 public:
  int numberOfPatterns(int m, int n)
  {
    vector<vector<bool>> grid(3, vector<bool>(3, false));
    return 4 * dfs(grid, 0, 0, 1, m, n) + 4 * dfs(grid, 0, 1, 1, m, n) +
           dfs(grid, 1, 1, 1, m, n);
  }

  int dfs(vector<vector<bool>>& grid, int r, int c, int d, int m, int n)
  {
    int cnt = d >= m;
    if (d >= n) return cnt;
    grid[r][c] = true;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (!grid[i][j] && neighbor(grid, r, c, i, j))
          cnt += dfs(grid, i, j, d + 1, m, n);
    grid[r][c] = false;
    return cnt;
  }

  bool neighbor(vector<vector<bool>>& grid, int i0, int j0, int i1, int j1)
  {
    int dr = abs(i0 - i1);
    int dc = abs(j0 - j1);
    if (dr <= 1 && dc <= 1) return true;
    if (dc <= 1) return dc || grid[(i0 + i1) / 2][j0];
    if (dr <= 1) return dr || grid[i0][(j0 + j1) / 2];
    return grid[1][1];
  }
};
