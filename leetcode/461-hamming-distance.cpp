class Solution
{
 public:
  int hammingDistance(int x, int y)
  {
    int z = x ^ y;
    int d = 0;
    for (; z; z >>= 1) d += z & 1;
    return d;
  }
};
