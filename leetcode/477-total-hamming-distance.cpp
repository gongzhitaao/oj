class Solution
{
 public:
  int totalHammingDistance(vector<int>& nums)
  {
    int d = 0;
    for (int i = 1; i < 1000000000; i <<= 1) {
      int k = 0;
      for (int n : nums)
        if (n & i) ++k;
      d += k * (nums.size() - k);
    }
    return d;
  }
};
