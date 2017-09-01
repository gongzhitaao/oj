class Solution
{
 public:
  int minPathSum(vector<vector<int>>& grid)
  {
    typedef tuple<int, int, int> data_t;
    struct cmp {
      bool operator()(const data_t& a, const data_t& b)
      {
        return get<0>(a) > get<0>(b);
      }
    };

    const int row = grid.size(), col = grid[0].size();
    vector<vector<int>> d(row, vector<int>(col, 0));
    d[0][0] = grid[0][0];
    const vector<int> D{0, 1, 0};

    priority_queue<data_t, vector<data_t>, cmp> q;
    for (q.push({0, 0, 0}); q.size(); ) {
      data_t cur = q.top(); q.pop();
      int r = get<1>(cur), c = get<2>(cur);
      for (int i = 0; i < 2; ++i) {
        int rr = r + D[i], cc = c + D[i + 1];
        if (rr < row && cc < col && !d[rr][cc]) {
          d[rr][cc] = d[r][c] + grid[rr][cc];
          if (row - 1 == rr && col - 1 == cc)
            break;
          q.push({d[rr][cc], rr, cc});
        }
      }
    }

    return d[row - 1][col - 1];
  }
};
