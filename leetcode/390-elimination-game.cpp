class Solution
{
 public:
  int lastRemaining(int n)
  {
    if (1 == n) return 1;
    int m = n - (n + 1) / 2;
    int p = m + 1 - lastRemaining(m);
    return p * 2;
  }
};
