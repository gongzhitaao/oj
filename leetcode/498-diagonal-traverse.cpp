class Solution
{
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
  {
    if (matrix.empty() || matrix[0].empty()) return {};

    const int ROW = matrix.size(), COL = matrix[0].size();
    const int N = ROW * COL;
    const vector<int> DIR{-1, 1, -1};
    vector<int> ret(N, 0);
    for (int k = 0, i = 0, j = 0, d = 0; k < N; ++k) {
      cout << i << ' ' << j << endl;
      ret[k] = (matrix[i][j]);
      i += DIR[d], j += DIR[d + 1];

      if (j >= COL) j = COL - 1, i += 2, d = 1 - d;
      if (i >= ROW) i = ROW - 1, j += 2, d = 1 - d;
      if (i < 0) i = 0, d = 1 - d;
      if (j < 0) j = 0, d = 1 - d;
    }
    return ret;
  }
};
