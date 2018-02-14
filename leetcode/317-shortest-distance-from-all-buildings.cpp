class Solution
{
  typedef pair<int, int> id_t;

 public:
  int shortestDistance(vector<vector<int>>& grid)
  {
    if (grid.empty() || grid[0].empty()) return -1;

    nrow_ = grid.size();
    ncol_ = grid[0].size();

    c_.resize(nrow_, vector<int>(ncol_, 0));
    d_.resize(nrow_, vector<int>(ncol_, 0));

    int total = 0;
    for (int i = 0; i < nrow_; ++i)
      for (int j = 0; j < ncol_; ++j)
        if (1 == grid[i][j]) {
          bfs(grid, i, j);
          ++total;
        }

    int min = -1;
    for (int i = 0; i < nrow_; ++i)
      for (int j = 0; j < ncol_; ++j)
        if (!grid[i][j] && c_[i][j] == total && (min < 0 || d_[i][j] < min))
          min = d_[i][j];
    return min;
  }

  void bfs(const vector<vector<int>>& grid, int r, int c)
  {
    queue<id_t> q;
    q.push({r, c});
    vector<vector<bool>> v(nrow_, vector<bool>(ncol_, false));
    vector<vector<int>> t(nrow_, vector<int>(ncol_, 0));
    while (!q.empty()) {
      id_t p = q.front();
      q.pop();
      for (id_t child : vector<id_t>{
             {p.first - 1, p.second},  // up
             {p.first, p.second + 1},  // right
             {p.first + 1, p.second},  // down
             {p.first, p.second - 1}   // left
           }) {
        int i = child.first, j = child.second;
        if (bounded(i, j) && !v[i][j] && !grid[i][j]) {
          v[i][j] = true;
          t[i][j] = t[p.first][p.second] + 1;
          d_[i][j] += t[i][j];
          ++c_[i][j];
          q.push(child);
        }
      }
    }
  }

  inline bool bounded(int r, int c)
  {
    return r >= 0 && r < nrow_ && c >= 0 && c < ncol_;
  }

 private:
  int nrow_, ncol_;
  vector<vector<int>> c_, d_;
};
