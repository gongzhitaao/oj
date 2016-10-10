class Solution
{
 public:
  bool isPerfectSquare(int num)
  {
    for (int l = 1, h = num; l <= h; /* empty */) {
      long long m = l + (h - l) / 2;
      long long sqr = m * m;
      if (sqr == num) return true;
      if (sqr < num) l = m + 1;
      else h = m - 1;
    }
    return false;
  }
};
