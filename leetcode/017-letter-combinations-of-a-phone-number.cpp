class Solution
{
 public:
  vector<string> letterCombinations(string digits)
  {
    vector<string> ret;

    if (digits.empty())
      return ret;
    for (char ch : digits)
      if (ch < '2' || ch > '9')
        return ret;

    vector<string> dicts{
      "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    dfs(0, "", digits, dicts, ret);
    return ret;
  }

 private:
  void dfs(int i, string path, const string& digits,
           const vector<string>& dicts, vector<string>& ret)
  {
    if (i == digits.size())
      ret.push_back(path);

    for (char ch : dicts[digits[i]-'0'-2])
      dfs(i+1, path+ch, digits, dicts, ret);
  }
};
