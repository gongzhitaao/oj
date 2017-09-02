class Solution
{
 public:
  void nextPermutation(vector<int>& nums)
  {
    int n = nums.size(), p1, p2;
    for (p1 = n - 2; p1 >= 0 && nums[p1] >= nums[p1 + 1]; --p1);
    if (p1 >= 0) {
      for (p2 = n - 1; p2 > p1 + 1 && nums[p1] >= nums[p2]; --p2);
      swap(nums[p1], nums[p2]);
    }
    reverse(nums.begin() + p1 + 1, nums.end());
  }
};
