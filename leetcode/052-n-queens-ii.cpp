class Solution
{
 public:
  int totalNQueens(int n)
  {
    if (n < 1) return 0;

    vector<int> col(n, true);
    vector<int> d0(2 * n, true), d1(2 * n, true);
    return dfs(0, n, col, d0, d1);
  }

  int dfs(int i, int n, vector<int>& col, vector<int>& d0, vector<int>& d1)
  {
    if (i == n) return 1;

    int cnt = 0;
    int end = 0 == i ? n / 2 : n;

    for (int j = 0; j < end; ++j) {
      if (col[j] && d0[n - 1 - i + j] && d1[i + j]) {
        col[j] = d0[n - 1 - i + j] = d1[i + j] = false;
        cnt += dfs(i + 1, n, col, d0, d1);
        col[j] = d0[n - 1 - i + j] = d1[i + j] = true;
      }
    }

    if (0 == i) {
      cnt *= 2;
      if (n & 1) {
        int j = n / 2;
        col[j] = d0[n - 1 + j] = d1[j] = false;
        cnt += dfs(1, n, col, d0, d1);
        col[j] = d0[n - 1 + j] = d1[j] = true;
      }
    }

    return cnt;
  }
};
