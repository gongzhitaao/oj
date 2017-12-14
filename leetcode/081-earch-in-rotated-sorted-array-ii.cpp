class Solution
{
 public:
  bool search(vector<int>& nums, int target)
  {
    return bsearch(nums, 0, nums.size() - 1, target);
  }

  bool bsearch(vector<int>& nums, int lo, int hi, int target)
  {
    if (lo > hi) return false;
    if (lo == hi) return nums[lo] == target;

    int mi = lo + (hi - lo) / 2;
    if (target == nums[mi]) return true;

    if (nums[mi] > nums[lo]) {
      if (target > nums[mi]) return bsearch(nums, mi + 1, hi, target);
      if (target < nums[mi]) {
        if (target < nums[lo]) return bsearch(nums, mi + 1, hi, target);
        return bsearch(nums, lo, mi, target);
      }
    } else if (nums[mi] < nums[lo]) {
      if (target > nums[mi]) {
        if (target >= nums[lo]) return bsearch(nums, lo, mi, target);
        return bsearch(nums, mi + 1, hi, target);
      }
      return bsearch(nums, lo, mi - 1, target);
    } else
      return bsearch(nums, lo, mi, target) || bsearch(nums, mi + 1, hi, target);
  }
};
