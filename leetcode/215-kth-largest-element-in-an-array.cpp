class Solution
{
 public:
  int findKthLargest(vector<int>& nums, int k)
  {
    int lo, hi, mi;
    for (lo = 0, hi = nums.size() - 1; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      swap(nums[lo], nums[mi]);

      int p = lo;
      for (int j = lo + 1; j <= hi; ++j)
        if (nums[j] > nums[lo]) swap(nums[++p], nums[j]);
      swap(nums[lo], nums[p]);

      if (p + 1 == k) return nums[p];

      if (p + 1 < k) lo = p + 1;
      else hi = p - 1;
    }

    return nums[lo];
  }
};
