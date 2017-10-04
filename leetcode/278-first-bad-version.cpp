// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
 public:
  int firstBadVersion(int n)
  {
    int lo = 1, hi = n, mi;
    for (; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      if (!isBadVersion(mi))
        lo = mi + 1;
      else hi = mi;
    }
    return lo;
  }
};
