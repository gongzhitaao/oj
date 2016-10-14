class Solution
{
 public:
  vector<vector<int>>
  combinationSum(vector<int>& candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    return dfs(candidates, 0, target);
  }

  vector<vector<int>> dfs(vector<int>& cands, int i0, int target)
  {
    vector<vector<int>> ret;
    if (cands.empty() || i0 >= cands.size() || cands[i0] > target)
      return ret;

    int num = cands[i0];
    if (num == target) return {{num}};

    int n = target / num;
    for (int i = 0; i <= n; ++i) {
      vector<vector<int>> res = dfs(cands, i0+1, target-i*num);
      vector<int> cur(i, num);
      for (auto& e : res) {
        e.insert(e.end(), cur.begin(), cur.end());
        ret.push_back(e);
      }
    }

    if (0 == target % num) {
      vector<int> cur(n, num);
      ret.push_back(cur);
    }

    return ret;
  }
};
