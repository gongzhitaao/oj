class Solution
{
 public:
  struct Node {
    bool word;
    int cnt;
    array<Node*, 26> next;
    Node() {
      cnt = 0;
      word = false;
      next.fill(nullptr);
    }
  };

  vector<string>
  findWords(vector<vector<char> >& board, vector<string>& words)
  {
    vector<string> ret;
    if (board.empty() || board[0].empty() || words.empty())
      return ret;

    Node* head = new Node();
    for (string& w : words) {
      Node* cur = head;
      for (char c : w) {
        int idx = c - 'a';
        if (!cur->next[idx]) {
          cur->next[idx] = new Node();
          ++(cur->cnt);
        }
        cur = cur->next[idx];
      }
      cur->word = true;
    }

    int nrow = board.size(), ncol = board[0].size();
    vector<vector<bool> > v(nrow, vector<bool>(ncol, false));
    for (int i = 0; i < nrow; ++i)
      for (int j = 0; j < ncol; ++j)
        if (head->next[board[i][j]-'a'])
          dfs(board, i, j, head->next[board[i][j]-'a'],
              string()+board[i][j], ret, v);
    return ret;
  }

  bool dfs(vector<vector<char> >& board, int r, int c,
           Node* node, string path, vector<string>& ret,
           vector<vector<bool> >& v)
  {
    v[r][c] = true;

    if (node->word) {
      node->word = false;
      ret.push_back(path);
    }

    static const vector<int> step = {-1, 0, 1, 0, -1};
    int nrow = board.size(), ncol = board[0].size();
    for (int i = 0; i < 4; ++i) {
      int rr = r + step[i], cc = c + step[i+1];
      if (0 <= rr && rr < nrow && 0 <= cc && cc < ncol
          && !v[rr][cc] && node->next[board[rr][cc]-'a'])
        if (dfs(board, rr, cc, node->next[board[rr][cc]-'a'],
                path+board[rr][cc], ret, v)) {
          delete node->next[board[rr][cc]-'a'];
          node->next[board[rr][cc]-'a'] = nullptr;
          --node->cnt;
        }
    }

    v[r][c] = false;
    return 0 == node->cnt;
  }
};
