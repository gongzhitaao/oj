class Solution {
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    const int size = 9;

    // each row
    for (int i = 0; i < 9; ++i) {
      vector<bool> b(size, false);
      for (int j = 0; j < 9; ++j) {
        if ('.' != board[i][j]) {
          if (b[board[i][j] - '0']) return false;
          b[board[i][j] - '0'] = true;
        }
      }
    }

    // each col
    for (int j = 0; j < 9; ++j) {
      vector<bool> b(size, false);
      for (int i = 0; i < 9; ++i) {
        if ('.' != board[i][j]) {
          if (b[board[i][j] - '0']) return false;
          b[board[i][j] - '0'] = true;
        }
      }
    }

    // each grid
    for (int r = 1; r < 10; r += 3) {
      for (int c = 1; c < 10; c += 3) {
        vector<bool> b(size, false);
        for (int i = r - 1; i <= r + 1; ++i) {
          for (int j = c - 1; j <= c + 1; ++j) {
            if ('.' != board[i][j]) {
              if (b[board[i][j] - '0']) return false;
              b[board[i][j] - '0'] = true;
            }
          }
        }
      }
    }

    return true;
  }
};
