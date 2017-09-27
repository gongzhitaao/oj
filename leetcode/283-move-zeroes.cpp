class Solution
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    int i = 0;
    for (; i < nums.size() && 0 != nums[i]; ++i)
      ;
    for (int j = i + 1; j < nums.size(); ++j)
      if (0 != nums[j]) swap(nums[i++], nums[j]);
  }
};
