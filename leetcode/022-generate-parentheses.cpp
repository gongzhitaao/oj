class Solution
{
 public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> ret;
    dfs("", 0, n, ret);
    return ret;
  }

  void dfs(string path, int d, int n, vector<string>& ret)
  {
    if (!n) return ret.push_back(path+string(d, ')'));
    dfs(path+"(", d+1, n-1, ret);
    if (d) dfs(path+")", d-1, n, ret);
  }
};
