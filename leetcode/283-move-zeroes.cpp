class Solution
{
 public:
  void moveZeroes(vector<int>& nums)
  {
    int cnt0 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (!nums[i]) ++cnt0;
      else nums[i-cnt0] = nums[i];
    }
    fill(nums.begin()+nums.size()-cnt0, nums.end(), 0);
  }
};
