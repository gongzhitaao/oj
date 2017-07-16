class Solution
{
 public:
  int search(vector<int>& nums, int target)
  {
    if (nums.empty()) return -1;

    int pivot = nums[0], n = nums.size();
    if (target == pivot) return 0;
    int lo = 0, mi, hi = n - 1;
    if (target > pivot) {
      while (lo < hi) {
        mi = lo + (hi - lo + 1) / 2;
        if (target == nums[mi]) return mi;
        if (target < nums[mi] || nums[mi] < pivot) hi = mi - 1;
        else lo = mi + 1;
      }
    } else {
      while (lo < hi) {
        mi = lo + (hi - lo + 1) / 2;
        if (target == nums[mi]) return mi;
        if (target > nums[mi] || nums[mi] > pivot) lo = mi + 1;
        else hi = mi - 1;
      }
    }

    return nums[hi] == target ? hi : -1;
  }
};
