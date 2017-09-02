class Solution
{
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    vector<vector<int>> ret;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target, {}, ret);
    return ret;
  }

  void dfs(const vector<int>& cands, int p0, int target, vector<int> path,
           vector<vector<int>>& res)
  {
    if (!target)
      return res.push_back(path);
    if (p0 >= cands.size() || cands[p0] > target)
      return;

    int cnt = 0;
    for (int i = p0; i < cands.size() && cands[p0] == cands[i]; ++i)
      ++cnt;

    dfs(cands, p0 + cnt, target, path, res);
    for (int i = 1; i <= cnt; ++i) {
      path.push_back(cands[p0]);
      dfs(cands, p0 + cnt, target -= cands[p0], path, res);
    }
  }
};
