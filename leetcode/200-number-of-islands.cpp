class Solution
{
 public:
  int numIslands(vector<vector<char> >& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;

    int nrow = grid.size(), ncol = grid[0].size();

    typedef pair<int, int> id;

    set<id> lands;
    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if ('1' == grid[i][j]) lands.insert({i, j});

    const vector<int> step{-1, 0, 1, 0, -1};

    int cnt = 0;
    for (; !lands.empty(); ++cnt) {
      id cur = *lands.begin(); lands.erase(cur);
      queue<id> q;
      q.push(cur);
      while (!q.empty()) {
        id p = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
          int r = p.first + step[i], c = p.second + step[i+1];
          if (0 <= r && r < nrow && 0 <= c && c < ncol &&
              '1' == grid[r][c] &&
              lands.find({r, c}) != lands.end()) {
            lands.erase({r, c});
            q.push({r, c});
          }
        }
      }
    }

    return cnt;
  }
};
