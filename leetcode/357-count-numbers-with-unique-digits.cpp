class Solution
{
 public:
  int countNumbersWithUniqueDigits(int n)
  {
    if (!n) return 1;
    int ret = 10, tmp = 9;
    for (int i = 2; i <= min(n, 10); ++i)
      ret += (tmp *= 11-i);
    return ret;
  }
};
