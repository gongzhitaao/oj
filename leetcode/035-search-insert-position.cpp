class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    for (int cnt = nums.size(); cnt > 0; ) {
      int step = cnt / 2;
      int m = l + step;
      if (nums[m] < target) {
        l = m + 1;
        cnt -= step + 1;
      } else cnt = step;
    }
    return l;
  }
};
