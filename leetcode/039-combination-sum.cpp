class Solution
{
 public:
  vector<vector<int> >
  combinationSum(vector<int>& candidates, int target)
  {
    dfs(candidates, 0, target);
    return ret_;
  }

  void dfs(vector<int>& cands, int i0, int target)
  {
    if (0 > target) return;
    if (0 == target) {
      ret_.push_back(sol_);
      return;
    }

    sol_.push_back(0);
    for (int i = i0; i < cands.size(); ++i) {
      sol_.back() = cands[i];
      dfs(cands, i, target - cands[i]);
    }
    sol_.pop_back();
  }

 private:
  vector<int> sol_;
  vector<vector<int> > ret_;
};
