class Solution
{
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix)
  {
    int maxlen = 0;
    if (matrix.empty() || matrix[0].empty()) return maxlen;

    const int row = matrix.size(), col = matrix[0].size();

    vector<vector<int>> len(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (dfs(matrix, i, j, len) > maxlen) maxlen = len[i][j];

    return maxlen;
  }

  int dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& len)
  {
    if (len[i][j]) return len[i][j];
    const int row = mat.size(), col = mat[0].size();

    len[i][j] = 1;
    if (i > 0 && mat[i][j] > mat[i - 1][j] &&
        dfs(mat, i - 1, j, len) + 1 > len[i][j])
      len[i][j] = len[i - 1][j] + 1;
    if (j < col - 1 && mat[i][j] > mat[i][j + 1] &&
        dfs(mat, i, j + 1, len) + 1 > len[i][j])
      len[i][j] = len[i][j + 1] + 1;
    if (i < row - 1 && mat[i][j] > mat[i + 1][j] &&
        dfs(mat, i + 1, j, len) + 1 > len[i][j])
      len[i][j] = len[i + 1][j] + 1;
    if (j > 0 && mat[i][j] > mat[i][j - 1] &&
        dfs(mat, i, j - 1, len) + 1 > len[i][j])
      len[i][j] = len[i][j - 1] + 1;

    return len[i][j];
  }
};
