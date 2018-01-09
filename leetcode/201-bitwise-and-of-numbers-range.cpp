class Solution
{
 public:
  int rangeBitwiseAnd(int m, int n)
  {
    int ret = 0;
    for (int i = 0; i < 31; ++i) {
      int mask = 1 << i;
      if (n - m <= mask - 1) ret = ret | (n & m & mask);
    }
    return ret;
  }
};
