class Solution
{
 public:
  int findPeakElement(vector<int>& nums)
  {
    int lo, n;
    for (lo = 0, n = nums.size(); n > 1; ) {
      int mi = lo + n/2;
      if (nums[mi] > nums[mi-1]) lo = mi, n -= n/2;
      else n = n/2;
    }
    return lo;
  }
};
