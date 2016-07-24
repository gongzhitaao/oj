class Solution {
public:
  int minPathSum(vector<vector<int> >& grid) {
    struct node {
      int d, r, c;
      node(int d, int r, int c) : d(d), r(r), c(c) { }
    };
    struct comp {
      bool operator() (const node& a, const node& b) {
        return a.d > b.d;
      }
    };

    int row = grid.size(), col = grid[0].size();

    int d[row][col];
    fill((int*)d, (int*)d + row * col, numeric_limits<int>::max());

    d[0][0] = grid[0][0];
    priority_queue<node, std::vector<node>, comp> q;
    q.push(node(d[0][0], 0, 0));
    while (!q.empty()) {
      node n = q.top(); q.pop();
      if (n.r < row - 1) d
    }
  }
};
