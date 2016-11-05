class Solution
{
 public:
  vector<string> generateAbbreviations(string word)
  {
    vector<string> ret;
    dfs(word, "", 0, ret);
    return ret;
  }

  void dfs(string word, string path, int n, vector<string>& ret)
  {
    if (word.empty())
      return ret.push_back(path + (n ? to_string(n) : ""));
    string next = word.substr(1);
    dfs(next, path, n+1, ret);
    dfs(next, path + (n ? to_string(n) : "") + word[0], 0, ret);
  }
};
