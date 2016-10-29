class Solution
{
 public:
  int numIslands(vector<vector<char> >& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;

    int nrow = grid.size(), ncol = grid[0].size();
    const vector<int> step{-1, 0, 1, 0, -1};

    typedef pair<int, int> id;
    int cnt = 0;
    queue<id> q;
    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        if ('0' == grid[i][j]) continue;
        ++cnt;
        for (q.push({i, j}); !q.empty(); ) {
          id p = q.front(); q.pop();
          for (int k = 0; k < 4; ++k) {
            int r = p.first + step[k], c = p.second + step[k+1];
            if (0 <= r && r < nrow && 0 <= c && c < ncol &&
                '1' == grid[r][c]) {
              grid[r][c] = '0';
              q.push({r, c});
            }
          }
        }
      }
    }
    return cnt;
  }
};
