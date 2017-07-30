class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int len = 1, pos = 1, pre = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != pre) {
        pre = nums[i];
        nums[pos] = pre;
        ++pos;
        ++len;
      }
    }

    return len;
  }
};
