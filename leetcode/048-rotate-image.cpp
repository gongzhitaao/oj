class Solution
{
 public:
  void rotate(vector<vector<int>>& matrix)
  {
    const int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
      int k = n - i - 1;
      for (int j = i; j < k; ++j) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[k][n - 1 - j];
        matrix[k][n - 1 - j] = matrix[j][k];
        matrix[j][k] = tmp;
      }
    }
  }
};
