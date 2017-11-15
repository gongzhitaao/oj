class TicTacToe
{
  vector<vector<int>> vsum_, hsum_;
  int dsum0_, dsum1_, winner_;

 public:
  /** Initialize your data structure here. */
  TicTacToe(int n)
  {
    vsum_ = vector<vector<int>>(2, vector<int>(n, 0));
    hsum_ = vector<vector<int>>(2, vector<int>(n, 0));
    dsum0_ = 0;
    dsum1_ = 0;
    winner_ = 0;
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
    if (winner_) return winner_;

    int inc = 2 * player - 3;
    int n = vsum_[0].size();

    vsum_[player - 1][col] += inc;
    hsum_[player - 1][row] += inc;
    if (row == col) dsum0_ += inc;
    if (row + col == n - 1) dsum1_ += inc;

    n *= inc;
    if (n == vsum_[player - 1][col] || n == hsum_[player - 1][row] ||
        n == dsum0_ || n == dsum1_)
      winner_ = player;

    return winner_;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
