class NumMatrix {
 public:
  NumMatrix(const vector<vector<int> >& matrix)
  {
    mat_ = matrix;
    int nrow = mat_.size() + 1;
    int ncol = nrow > 1 ? mat_[0].size() + 1 : 1;

    bit_ = vector<vector<int>>(nrow, vector<int>(ncol, 0));

    for (int i = 1; i < nrow; ++i)
      for (int j = 1; j < ncol; ++j)
        update_bit(i, j, mat_[i-1][j-1]);
  }

  void update(int row, int col, int val)
  {
    int delta = val - mat_[row][col];
    mat_[row][col] = val;
    update_bit(row+1, col+1, delta);
  }

  void update_bit(int row, int col, int delta)
  {
    int nrow = bit_.size(), ncol = bit_[0].size();
    for (int i = row; i < nrow; i += i & -i)
      for (int j = col; j < ncol; j += j & -j)
        bit_[i][j] += delta;
  }

  int sum_bit(int row, int col)
  {
    int sum = 0;
    for (int i = row; i > 0; i -= i & -i)
      for (int j = col; j > 0; j -= j & -j)
        sum += bit_[i][j];
    return sum;
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return sum_bit(row2+1, col2+1)
        - sum_bit(row2+1, col1) - sum_bit(row1, col2+1)
        + sum_bit(row1, col1);
  }

 private:
  vector<vector<int>> mat_;
  vector<vector<int>> bit_;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
