class Solution
{
 public:
  int findKthLargest(vector<int>& nums, int k)
  {
    make_heap(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < k - 1; ++i, --n)
      pop_heap(nums.begin(), nums.begin()+n);
    return nums[0];
  }
};
