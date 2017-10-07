class Solution
{
 public:
  void sortColors(vector<int>& nums)
  {
    for (int i = -1, j = nums.size(), k = 0; k < j; ) {
      if (0 == nums[k]) swap(nums[k++], nums[++i]);
      else if (1 == nums[k]) ++k;
      else swap(nums[k], nums[--j]);
    }
  }
};
