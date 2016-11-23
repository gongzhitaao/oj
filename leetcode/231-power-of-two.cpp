class Solution
{
 public:
  bool isPowerOfTwo(int n)
  {
    if (n <= 0) return false;
    for (int i = n; i; i >>= 1)
      if ((i & 1) && (i >> 1))
        return false;
    return true;
  }
};
