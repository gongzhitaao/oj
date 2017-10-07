class Solution
{
 public:
  vector<vector<int>> subsets(vector<int>& nums)
  {
    vector<vector<int>> ret = {{}};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0, n = ret.size(); j < n; ++j) {
        vector<int> v = ret[j];
        v.push_back(nums[i]);
        ret.push_back(v);
      }
    }
    return ret;
  }
};
