class Solution
{
 public:
  int minTotalDistance(vector<vector<int>>& grid)
  {
    if (grid.empty() || grid[0].empty()) return 0;
    const int row = grid.size(), col = grid[0].size();
    vector<int> x, y;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (grid[i][j]) x.push_back(i), y.push_back(j);
    vector<int> xcopy = x, ycopy = y;
    nth_element(x.begin(), x.begin() + x.size() / 2, x.end());
    nth_element(y.begin(), y.begin() + y.size() / 2, y.end());
    int xmid = x[x.size() / 2], ymid = y[y.size() / 2];
    int dist = 0;
    for (int n : x) dist += abs(n - xmid);
    for (int n : y) dist += abs(n - ymid);
    return dist;
  }
};
