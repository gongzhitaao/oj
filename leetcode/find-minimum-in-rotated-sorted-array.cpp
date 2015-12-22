class Solution {
public:
  int findMin(vector<int>& nums) {
    for (int beg = 0, end = nums.size(); beg < end;) {
      if (nums[beg] <= nums[end - 1]) return nums[beg];

      int mid = (beg + end) / 2;
      if (nums[mid - 1] > nums[mid]) return nums[mid];
      if (nums[beg] < nums[mid]) beg = mid + 1;
      else end = mid;
    }
  }
};
