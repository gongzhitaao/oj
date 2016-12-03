class Solution
{
 public:
  int integerReplacement(int n)
  {
    int cnt = 0;
    for (long long i = n; i-1; ++cnt) {
      if (i & 1) {
        if (i != 3 && (i & 2)) ++i;
        else --i;
      } else i >>= 1;
    }
    return cnt;
  }
};
