class Solution
{
 public:
  int findTargetSumWays(vector<int>& nums, int S)
  {
    return dfs(nums, 0, S);
  }

  int dfs(const vector<int>& nums, int i0, int target)
  {
    if (i0 == nums.size()) return 0 == target;

    if (0 == nums[i0])
      return 2 * dfs(nums, i0 + 1, target);
    else
      return dfs(nums, i0 + 1, target - nums[i0]) +
             dfs(nums, i0 + 1, target + nums[i0]);
  }
};
