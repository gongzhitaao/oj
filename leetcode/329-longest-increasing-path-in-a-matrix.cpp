class Solution
{
 public:
  int longestIncreasingPath(vector<vector<int> >& matrix)
  {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int nrow = matrix.size(), ncol = matrix[0].size();
    vector<vector<int> > d(nrow, vector<int>(ncol, 0));
    int maxlen = 1;
    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        int len = dfs(matrix, d, i, j);
        if (len > maxlen) maxlen = len;
      }
    }
    return maxlen;
  }

  int dfs(vector<vector<int> >& mat, vector<vector<int> >& d,
          int r, int c)
  {
    if (d[r][c] > 0) return d[r][c];

    int maxlen = 0;
    int nrow = mat.size(), ncol = mat[0].size();
    static const vector<int> step = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; ++i) {
      int rr = r + step[i], cc = c + step[i+1];
      if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol &&
          mat[rr][cc] > mat[r][c]) {
        int len = dfs(mat, d, rr, cc);
        if (len > maxlen) maxlen = len;
      }
    }
    return d[r][c] = maxlen + 1;
  }
};
