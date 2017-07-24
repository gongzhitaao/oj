class Solution
{
 public:
  int mySqrt(int x)
  {
    if (!x) return 0;

    int lo, hi;
    for (lo = 1, hi = 46340; lo < hi; ) {
      int mi = lo + (hi - lo) / 2;
      int xx = mi * mi;
      if (xx == x) return mi;
      if (xx < x) lo = mi + 1;
      else hi = mi - 1;
    }

    return lo*lo > x ? lo-1 : lo;
  }
};
