class Solution {
public:
  void sortColors(vector<int>& nums) {
    for (int i = 0, j = nums.size() - 1, k = 0; k <= j; ) {
      if (0 == nums[k]) {
        swap(nums[i], nums[k]);
        ++i;
        ++k;
      } else if (2 == nums[k]) {
        swap(nums[j], nums[k]);
        --j;
      } else {
        ++k;
      }
    }
  }
};
