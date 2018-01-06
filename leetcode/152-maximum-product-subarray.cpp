class Solution
{
 public:
  int maxProduct(vector<int>& nums)
  {
    int ret = numeric_limits<int>::min();
    int maxp = -1, maxn = 1;
    for (int n : nums) {
      if (n > 0) {
        if (maxp > 0)
          maxp *= n;
        else
          maxp = n;
        if (maxp > ret) ret = maxp;
        if (maxn < 0) maxn *= n;
      } else if (0 == n) {
        maxp = -1;
        maxn = 1;
        if (ret < 0) ret = 0;
      } else {
        int tmp = maxn;
        if (maxp > 0)
          maxn = maxp * n;
        else
          maxn = n;
        if (maxn > ret) ret = maxn;
        if (tmp < 0) {
          maxp = tmp * n;
          if (maxp > ret) ret = maxp;
        } else
          maxp = -1;
      }
    }
    return ret;
  }
};
