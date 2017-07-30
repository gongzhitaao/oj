class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int mask = 0;
    for (int i : nums) mask ^= i;
    mask &= -mask;

    int j = 0, k = 0;
    for (int i : nums) {
      if (i & mask) j ^= i;
      else k ^= i;
    }

    return {j, k};
  }
};
