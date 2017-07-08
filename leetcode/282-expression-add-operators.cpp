class Solution
{
 public:
  vector<string> addOperators(string num, int target)
  {
    vector<string> ret;
    long long arg0 = 0;
    for (int i = 0; i < num.size(); ++i) {
      arg0 = arg0 * 10 + num[i] - '0';
      if (arg0 > numeric_limits<int>::max()) break;
      dfs(num, i+1, ret, num.substr(0, i+1), target-arg0, -arg0);
      if (!arg0) break;
    }
    return ret;
  }

 private:
  void dfs(const string& num, int start,
           vector<string> &ret, string path,
           int res, int arg0)
  {
    if (num.size() <= start && !res)
      return ret.push_back(path);

    long long arg1 = 0;
    string arg1str = "";
    for (int i = start; i < num.size(); ++i) {
      arg1 = arg1 * 10 + num[i] - '0';
      if (arg1 > numeric_limits<int>::max()) break;
      arg1str += num[i];
      dfs(num, i+1, ret, path + '*' + arg1str, res - arg0 + arg0*arg1, arg0*arg1);
      dfs(num, i+1, ret, path + '-' + arg1str, res + arg1, arg1);
      dfs(num, i+1, ret, path + '+' + arg1str, res - arg1, -arg1);
      if (!arg1) break;
    }
  }
};
