class Solution
{
 public:
  vector<vector<int>> generateMatrix(int n)
  {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    const vector<int> D{0, 1, 0, -1, 0};

    for (int i = 1, d = 0, r = 0, c = -1; i <= n * n; ++i) {
      int rr = r + D[d], cc = c + D[d + 1];
      d += rr < 0 || rr >= n || cc < 0 || cc >= n || mat[rr][cc] > 0;
      d %= 4;
      r += D[d], c += D[d + 1];
      mat[r][c] = i;
    }

    return mat;
  }
};
