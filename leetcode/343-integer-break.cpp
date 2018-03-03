class Solution
{
 public:
  int integerBreak(int n)
  {
    if (2 == n) return 1;
    if (3 == n) return 2;
    int ret = 1;
    for (; n > 4; n -= 3) ret *= 3;
    return ret * n;
  }
};
