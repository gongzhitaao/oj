class Solution
{
 public:
  vector<string> findWords(vector<string>& words)
  {
    const vector<vector<char>> keys = {
        {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
        {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};

    vector<int> row(128, 0);
    for (int i = 0; i < 3; ++i)
      for (char c : keys[i])
        row[c] = row[c + 'A' - 'a'] = i;

    vector<string> ret;
    for (string& w : words) {
      int i = 0;
      for (i = 0; i < w.size(); ++i)
        if (row[w[i]] != row[w[0]]) break;
      if (i == w.size())
        ret.push_back(w);
    }

    return ret;
  }
};
