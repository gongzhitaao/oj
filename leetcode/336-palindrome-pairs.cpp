class Solution
{
 public:
  struct Node
  {
    int idx;
    unordered_map<char, Node*> next;
    Node() : idx(-1) { }
  };
  vector<vector<int> > palindromePairs(vector<string>& words)
  {
    int n = words.size();
    Node* head = new Node();
    for (int i = 0; i < n; ++i) {
      Node* cur = head;
      for (int j = words[i].size()-1; j >= 0; --j) {
        char c = words[i][j];
        if (cur->next.find(c) == cur->next.end())
          cur->next[c] = new Node();
        cur = cur->next[c];
      }
      cur->idx = i;
    }

    vector<vector<int> > ret;
    for (int i = 0; i < n; ++i) {
      Node* cur = head;
      string w = words[i];
      int m = w.size(), j = 0;
      if (cur->idx >= 0 && cur->idx != i && ispal(w))
        ret.push_back({i, cur->idx});
      for (; j < m && cur->next.find(w[j]) != cur->next.end(); ++j) {
        cur = cur->next[w[j]];
        if (cur->idx >= 0 && cur->idx != i && ispal(w.substr(j+1)))
          ret.push_back({i, cur->idx});
      }
      if (j == m)
        for (auto e : cur->next)
          dfs(e.second, string()+e.first, ret, i);
    }
    return ret;
  }

  inline bool ispal(string str)
  {
    for (int i = 0, j = str.size()-1; i < j; ++i, --j)
      if (str[i] != str[j]) return false;
    return true;
  }

  void dfs(Node* cur, string path, vector<vector<int> >& ret, int x)
  {
    if (cur->idx >= 0 && ispal(path))
      ret.push_back({x, cur->idx});
    for (auto e : cur->next)
      dfs(e.second, path+e.first, ret, x);
  }
};
