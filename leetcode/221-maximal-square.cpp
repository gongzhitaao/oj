class Solution
{
 public:
  int maximalSquare(vector<vector<char>>& matrix)
  {
    if (matrix.empty() || matrix[0].empty()) return 0;

    const int row = matrix.size(), col = matrix[0].size();
    vector<int> side(col+1, 0);

    int area = 0;
    for (int i = 0; i < row; ++i) {
      int tmp = 0;
      for (int j = 0; j < col; ++j) {
        int s = 0;
        if ('1' == matrix[i][j]) {
          s = min(min(side[j], side[j+1]), tmp) + 1;
          if (s * s > area) area = s * s;
        }
        tmp = side[j+1];
        side[j+1] = s;
      }
    }

    return area;
  }
};
