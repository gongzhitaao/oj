class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);

    for (int i = 1; i < nums.size(); ++i)
      ret[i] = nums[i - 1] * ret[i - 1];

    for (int i = ret.size() - 2, p = 1; i >= 0; --i) {
      p *= nums[i + 1];
      ret[i] *= p;
    }

    return ret;
  }
};
