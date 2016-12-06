class Solution
{
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums)
  {
    int n = nums.size();
    vector<bool> v(n+1, false);
    for (auto x : nums)
      v[x] = true;
    vector<int> ret;
    for (int i = 1; i <= n; ++i)
      if (!v[i]) ret.push_back(i);
    return ret;
  }
};
