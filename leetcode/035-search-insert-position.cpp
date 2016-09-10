class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    auto p = lower_bound(nums.begin(), nums.end(), target);
    return distance(nums.begin(), p);
  }
};
