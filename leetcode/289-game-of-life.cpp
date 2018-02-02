class Solution
{
 public:
  void gameOfLife(vector<vector<int>>& board)
  {
    int nrow, ncol;
    if (!(nrow = board.size()) || !(ncol = board[0].size())) return;

    const vector<int> step{-1, 0, 1, 0, -1, 1, 1, -1, -1};
    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        if (!(board[i][j] % 10)) continue;
        for (int k = 0; k < step.size() - 1; ++k) {
          int ii = i + step[k], jj = j + step[k + 1];
          if (0 <= ii && ii < nrow && 0 <= jj && jj < ncol) board[ii][jj] += 10;
        }
      }
    }

    for (int i = 0; i < nrow; ++i) {
      for (int j = 0; j < ncol; ++j) {
        int n = board[i][j] / 10;
        if (!(board[i][j] % 10) && 3 == n)
          board[i][j] = 1;
        else if (n < 2 || n > 3)
          board[i][j] = 0;
        else
          board[i][j] %= 10;
      }
    }
  }
};
