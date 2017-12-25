class Solution
{
 public:
  int singleNumber(vector<int>& nums)
  {
    int b0 = 0, b1 = 0;
    for (int n : nums) {
      b0 = ~b1 & (b0 ^ n);
      b1 = ~b0 & (b1 ^ n);
    }
    return b0;
  }
};
