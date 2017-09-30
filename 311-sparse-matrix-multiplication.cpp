class Solution
{
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
  {
    int a = A.size(), b = B.size(), c = B[0].size();
    vector<vector<int>> res(a, vector<int>(c, 0));
    for (int i = 0; i < a; ++i) {
      for (int k = 0; k < b; ++k) {
        if (0 == A[i][k]) continue;
        for (int j = 0; j < c; ++j) {
          if (B[k][j]) res[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return res;
  }
};
