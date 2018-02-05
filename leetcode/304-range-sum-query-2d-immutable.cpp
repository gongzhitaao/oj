class NumMatrix
{
  vector<vector<int>> sum_;

 public:
  NumMatrix(vector<vector<int>> matrix)
  {
    if (matrix.empty() || matrix[0].empty()) return;
    const int row = matrix.size(), col = matrix[0].size();
    sum_ = vector<vector<int>>(row + 1, (vector<int>(col + 1, 0)));
    for (int i = 1; i <= row; ++i)
      for (int j = 1; j <= col; ++j)
        sum_[i][j] = matrix[i - 1][j - 1] + sum_[i - 1][j] + sum_[i][j - 1] -
                     sum_[i - 1][j - 1];
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sum_[row2 + 1][col2 + 1] - sum_[row2 + 1][col1] -
           sum_[row1][col2 + 1] + sum_[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
