class Solution
{
 public:
  double myPow(double x, int n)
  {
    if (0 == n) return 1;

    double z = abs(x);
    int sign = signbit(x) && (n & 1) ? -1 : 1;
    double res = sign * bipart(z, n);
    if (n < 0) return 1 / res;
    return res;
  }

  double bipart(double x, int n)
  {
    if (0 == n) return 1;
    if (1 == n) return x;
    double xx = bipart(x, n / 2);
    if (n & 1) return xx * xx * x;
    return xx * xx;
  }
};
