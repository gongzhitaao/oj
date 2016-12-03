class Solution
{
 public:
  int combinationSum4(vector<int>& nums, int target)
  {
    vector<int> d(target+1, -1);
    d[0] = 1;
    search(nums, target, d);
    return d[target];
  }

  int search(vector<int>& nums, int target, vector<int>& d)
  {
    if (d[target] >= 0) return d[target];
    int cnt = 0;
    for (int n : nums)
      if (target-n >= 0)
        cnt += search(nums, target-n, d);
    return d[target] = cnt;
  }
};
