class Solution
{
 public:
  void solve(vector<vector<char>>& board)
  {
    if (board.empty() || board[0].empty()) return;

    const int row = board.size(), col = board[0].size();
    vector<vector<bool>> v(row, vector<bool>(col, false));

    for (int i = 0; i < row; ++i) {
      if ('O' == board[i][0] && !v[i][0]) dfs(board, i, 0, v);
      if ('O' == board[i][col - 1] && !v[i][col - 1]) dfs(board, i, col - 1, v);
    }

    for (int j = 0; j < col; ++j) {
      if ('O' == board[0][j] && !v[0][j]) dfs(board, 0, j, v);
      if ('O' == board[row - 1][j] && !v[row - 1][j]) dfs(board, row - 1, j, v);
    }

    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if ('O' == board[i][j] && !v[i][j]) board[i][j] = 'X';
  }

  void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& v)
  {
    v[i][j] = true;
    int row = board.size(), col = board[0].size();
    if (i > 0 && 'O' == board[i - 1][j] && !v[i - 1][j])
      dfs(board, i - 1, j, v);
    if (j < col - 1 && 'O' == board[i][j + 1] && !v[i][j + 1])
      dfs(board, i, j + 1, v);
    if (i < row - 1 && 'O' == board[i + 1][j] && !v[i + 1][j])
      dfs(board, i + 1, j, v);
    if (j > 0 && 'O' == board[i][j - 1] && !v[i][j - 1])
      dfs(board, i, j - 1, v);
  }
};
