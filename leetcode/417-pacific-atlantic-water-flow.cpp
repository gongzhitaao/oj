class Solution
{
 public:
  vector<pair<int, int> >
  pacificAtlantic(vector<vector<int> >& matrix)
  {
    vector<pair<int, int> > ret;
    if (matrix.empty() || matrix[0].empty())
      return ret;

    int nrow = matrix.size(), ncol = matrix[0].size();
    vector<vector<int> > v(nrow, vector<int>(ncol, 0));
    for (int i = 0; i < nrow; ++i) {
      dfs(matrix, v, i, 0, 1);
      dfs(matrix, v, i, ncol-1, 2);
    }
    for (int j = 0; j < ncol; ++j) {
      dfs(matrix, v, 0, j, 1);
      dfs(matrix, v, nrow-1, j, 2);
    }
    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (3 == v[i][j])
          ret.push_back({i, j});
    return ret;
  }

  void dfs(vector<vector<int> >& mat, vector<vector<int> >& v,
           int r, int c, int flag)
  {
    if (v[r][c] & flag) return;
    v[r][c] |= flag;
    int nrow = mat.size(), ncol = mat[0].size();
    static const vector<int> step = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int rr = r + step[i], cc = c + step[i+1];
      if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol &&
          mat[rr][cc] >= mat[r][c])
        dfs(mat, v, rr, cc, flag);
    }
  }
};
