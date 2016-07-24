class Solution {
 public:
  vector<vector<int> >
  combinationSum2(vector<int>& candidates, int target)
  {
    vector<bool> avail(candidates.size(), true);
    sort(candidates.begin(), candidates.end());
    return worker(candidates, avail, target, 0);
  }

  vector<vector<int> >
  worker(const vector<int>& candidates,
         vector<bool>& avail, int target, int beg)
  {
    vector<vector<int> > ret;
    for (int i = beg; i < candidates.size(); ++i) {
      if (!avail[i] || candidates[i] > target) continue;

      if (candidates[i] == target) {
        ret = {{target}};
      } else {
        avail[i] = false;
        vector<vector<int> > res = worker(
            candidates, avail, target - candidates[i], i + 1);
        avail[i] = true;

        for (auto& vec : res) {
          vec.push_back(candidates[i]);
          ret.push_back(vec);
        }
      }
    }

    return ret;
  }
};
