class Solution
{
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
  {
    const int ROW = matrix.size(), COL = matrix[0].size();
    vector<vector<int>> d(ROW, vector<int>(COL, ROW + COL));

    for (int i = 0; i < ROW; ++i) {
      for (int j = 0; j < COL; ++j)
        if (0 == matrix[i][j])
          d[i][j] = 0;
        else {
          if (i > 0) d[i][j] = min(d[i][j], d[i - 1][j] + 1);
          if (j > 0) d[i][j] = min(d[i][j], d[i][j - 1] + 1);
        }
    }

    for (int i = ROW - 1; i >= 0; --i) {
      for (int j = COL - 1; j >= 0; --j)
        if (matrix[i][j] > 0) {
          if (i < ROW - 1) d[i][j] = min(d[i][j], d[i + 1][j] + 1);
          if (j < COL - 1) d[i][j] = min(d[i][j], d[i][j + 1] + 1);
        }
    }

    return d;
  }
};
