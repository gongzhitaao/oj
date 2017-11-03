class Solution
{
 public:
  vector<int> searchRange(vector<int>& nums, int target)
  {
    int l = less_equal(nums, target);
    if (l < 0) return {-1, -1};
    int r = greater(nums, target);
    if (r < 0) return {-1, -1};
    return {l, r};
  }

  int less_equal(const vector<int>& nums, int target)
  {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums[mi] < target) lo = mi + 1;
      else hi = mi;
    }
    return nums.size() && nums[lo] == target ? lo : -1;
  }

  int greater(const vector<int>& nums, int target)
  {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (target < nums[mi]) hi = mi;
      else lo = mi + 1;
    }
    return nums.size() && nums[hi] > target ? hi - 1 : hi;
  }
};
