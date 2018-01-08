class Solution
{
 public:
  int findPeakElement(vector<int>& nums)
  {
    int lo = 0, hi = nums.size() - 1;
    for (int mi; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      if (nums[mi] > nums[mi + 1]) hi = mi;
      else lo = mi + 1;
    }
    return lo;
  }
};
