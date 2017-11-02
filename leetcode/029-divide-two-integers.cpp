class Solution
{
 public:
  int divide(int dividend, int divisor)
  {
    const int MAX = numeric_limits<int>::max();
    const int MIN = numeric_limits<int>::min();

    if (0 == divisor) return MAX;

    long long a = dividend, b = divisor;
    bool neg = a > 0 && b < 0 || a < 0 && b > 0;
    a = abs(a), b = abs(b);

    long long res = 0;
    for (; a >= b;) {
      long long cur = 1, tmp = b;
      for (; a >= tmp; tmp <<= 1, cur <<= 1)
        ;
      a -= tmp >> 1;
      res += cur >> 1;
    }

    if (neg) res = -res;
    return res < MIN || res > MAX ? MAX : res;
  }
};
