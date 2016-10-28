class Solution
{
 public:
  void wiggleSort(vector<int>& nums)
  {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
      if (i%2 && nums[i] < nums[i+1] ||
          !(i%2) && nums[i] > nums[i+1])
        swap(nums[i], nums[i+1]);
  }
};
