class Solution
{
 public:
  void setZeroes(vector<vector<int>>& matrix)
  {
    const int row = matrix.size(), col = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < row; ++i) {
      if (0 == matrix[i][0]) col0 = 0;
      for (int j = 1; j < col; ++j)
        if (0 == matrix[i][j]) matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = row - 1; i >= 0; --i) {
      for (int j = col - 1; j >= 1; --j)
        if (0 == matrix[i][0] || 0 == matrix[0][j]) matrix[i][j] = 0;
      if (0 == col0) matrix[i][0] = 0;
    }
  }
};
