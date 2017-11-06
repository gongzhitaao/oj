class Solution
{
 public:
  int splitArray(vector<int>& nums, int m)
  {
    int hi = 0, lo = nums[0];

    for (int n : nums) {
      hi += n;
      if (n > lo) lo = n;
    }

    for (; lo < hi; ) {
      int mi = lo + (hi - lo) / 2, sum = 0, cnt = 0;
      for (int n : nums) {
        if ((sum += n) > mi) {
          sum = n;
          if (++cnt > m) break;
        }
      }

      if (cnt >= m) lo = mi + 1;
      else hi = mi;
    }

    return lo;
  }
};
