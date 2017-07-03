class Solution
{
 public:
  bool exist(vector<vector<char>>& board, string word)
  {
    if (board.empty() || board[0].empty() || word.empty())
      return false;

    nrow_ = board.size(), ncol_ = board[0].size();

    for (int i = 0; i < nrow_; ++i)
      for (int j = 0; j < ncol_; ++j)
        if (board[i][j] == word[0] &&
            dfs(board, word, i, j, 1))
          return true;
    return false;
  }

 private:
  bool dfs(vector<vector<char>>& board, string& word,
           int row, int col, int ind)
  {
    if (word.size() == ind)
      return true;

    char ch = board[row][col];
    board[row][col] = 0;

    static const vector<int> d{-1, 0, 1, 0, -1};
    for (int i = 0, rr, cc; i < 4; ++i) {
      rr = row + d[i];
      if (rr < 0 || rr >= nrow_) continue;
      cc = col + d[i+1];
      if (cc < 0 || cc >= ncol_) continue;
      if (board[rr][cc] &&
          board[rr][cc] == word[ind] &&
          dfs(board, word, rr, cc, ind + 1))
        return true;
    }

    board[row][col] = ch;
    return false;
  }

  int nrow_, ncol_;
};
