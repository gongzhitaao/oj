class Solution
{
 public:
  bool canJump(vector<int>& nums)
  {
    if (nums.size() < 2) return true;

    for (int i = 1, bound = nums[0]; i < nums.size(); ++i) {
      if (bound < i) return false;
      if (bound >= nums.size() - 1) return true;
      if (i + nums[i] > bound)
        bound = i + nums[i];
    }
    return true;
  }
};
