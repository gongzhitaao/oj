class Solution
{
 public:
  int search(vector<int>& nums, int target)
  {
    if (nums.empty()) return -1;

    int lo, mi, hi;

    for (lo = 0, hi = nums.size() - 1; lo < hi; ) {
      mi = lo + (hi - lo + 1) / 2;
      if (nums[mi] > nums[0]) lo = mi;
      else hi = mi - 1;
    }

    if (target < nums[0]) lo = lo + 1, hi = nums.size() - 1;
    else hi = lo, lo = 0;

    for (; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      if (nums[mi] < target) lo = mi + 1;
      else hi = mi;
    }

    return lo <= hi && nums[lo] == target ? lo : -1;
  }
};
