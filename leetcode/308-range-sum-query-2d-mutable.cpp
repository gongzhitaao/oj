class NumMatrix {
 public:
  NumMatrix(vector<vector<int> > &matrix)
  {
    mat_ = matrix;
    int nrow = mat_.size() + 1;
    int ncol = nrow > 1 ? mat_[0].size() + 1 : 1;
    sum_ = vector<vector<int> >(nrow, vector<int>(ncol, 0));
    for (int i = 1; i < nrow; ++i)
      for (int j = 1; j < ncol; ++j)
        sum_[i][j] = mat_[i-1][j-1] +
                     sum_[i][j-1] + sum_[i-1][j] - sum_[i-1][j-1];
  }

  void update(int row, int col, int val)
  {
    int delta = val - mat_[row][col];
    mat_[row][col] = val;
    int nrow = sum_.size();
    int ncol = sum_[0].size();
    for (int i = row+1; i < nrow; ++i)
      for (int j = col+1; j < ncol; ++j)
        sum_[i][j] += delta;
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sum_[row2+1][col2+1]  + sum_[row1][col1] -
        sum_[row2+1][col1] - sum_[row1][col2+1];
  }

 private:
  vector<vector<int> > mat_;
  vector<vector<int> > sum_;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
