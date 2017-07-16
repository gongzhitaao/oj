class Solution
{
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
  {
    vector<vector<int>> ret{{}};
    if (nums.empty()) return ret;
    sort(nums.begin(), nums.end());

    for (int i = 0, j; i < nums.size(); i = j) {
      vector<vector<int>> tmp{{nums[i]}};
      for (j = i+1; j < nums.size() && nums[j]==nums[i]; ++j) {
        vector<int> cur = tmp.back();
        cur.push_back(nums[i]);
        tmp.push_back(cur);
      }
      int n = ret.size();
      for (int k = 0; k < n; ++k) {
        for (auto& v : tmp) {
          vector<int> cur = ret[k];
          cur.insert(cur.end(), v.begin(), v.end());
          ret.push_back(cur);
        }
      }
    }
    return ret;
  }
};
