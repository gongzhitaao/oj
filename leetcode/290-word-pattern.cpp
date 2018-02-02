class Solution
{
 public:
  bool wordPattern(string pattern, string str)
  {
    istringstream iss(str);
    vector<string> tokens{istream_iterator<string>(iss),
                          istream_iterator<string>()};
    if (pattern.size() != tokens.size()) return false;
    vector<string> c2w(128, "");
    unordered_map<string, char> w2c;
    for (int i = 0; i < pattern.size(); ++i) {
      char c = pattern[i];
      string& w = tokens[i];
      if (!c2w[c].empty() && c2w[c] != w ||
          w2c.find(w) != w2c.end() && w2c[w] != c)
        return false;
      if (c2w[i].empty()) c2w[c] = w;
      if (w2c.find(w) == w2c.end()) w2c[w] = c;
    }
    return true;
  }
};
