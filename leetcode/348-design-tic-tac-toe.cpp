class TicTacToe {
 public:
  /** Initialize your data structure here. */
  TicTacToe(int n)
  {
    n_ = n;
    rowcnt_ = vector<int>(n, 0);
    colcnt_ = vector<int>(n, 0);
    d0cnt_ = d1cnt_ = 0;
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
      0: No one wins.
      1: Player 1 wins.
      2: Player 2 wins. */
  int move(int row, int col, int player)
  {
    int m = 1 == player ? -1 : 1;
    rowcnt_[row] += m;
    if (rowcnt_[row] == m * n_) return player;
    colcnt_[col] += m;
    if (colcnt_[col] == m * n_) return player;
    if (row == col && (d0cnt_ += m) == m * n_ ||
        row+col == n_-1 && (d1cnt_ += m) == m * n_) return player;
    return 0;
  }

 private:
  vector<int> rowcnt_, colcnt_;
  int d0cnt_, d1cnt_;
  int n_;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
