class Solution
{
 public:
  int maxProduct(vector<int>& nums)
  {
    int ret = nums[0];
    for (int i = 1, nmin = ret, nmax = ret; i < nums.size(); ++i) {
      if (nums[i] < 0) swap(nmin, nmax);
      nmax = max(nums[i], nmax * nums[i]);
      nmin = min(nums[i], nmin * nums[i]);
      ret = max(ret, nmax);
    }
    return ret;
  }
};
