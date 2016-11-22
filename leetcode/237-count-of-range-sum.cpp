class Solution
{
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper)
  {
    int n = nums.size();
    if (!n) return 0;

    vector<long long> sums(n+1, 0);
    for (int i = 0; i < n; ++i)
      sums[i+1] = sums[i] + nums[i];

    return mergecount(sums, 1, n, lower, upper);
  }

  int mergecount(vector<long long>& sums, int i0, int n,
                 int lower, int upper)
  {
    if (1 == n)
      return lower <= sums[i0]-sums[i0-1] &&
          sums[i0]-sums[i0-1] <= upper;

    int n2 = n / 2;
    int a = mergecount(sums, i0, n2, lower, upper);
    int b = mergecount(sums, i0+n2, n-n2, lower, upper);
    int c = 0, i, j, k;

    for (i = 0; i < n2; ++i) {
      auto beg = lower_bound(sums.begin()+i0+n2, sums.begin()+i0+n,
                             lower+sums[i0+i-1]);
      auto end = upper_bound(sums.begin()+i0+n2, sums.begin()+i0+n,
                             upper+sums[i0+i-1]);
      c += distance(beg, end);
    }

    vector<long long> buf(sums.begin()+i0, sums.begin()+i0+n);
    for (i = 0, j = n2, k = i0; i < n2 && j < n; ++k) {
      if (buf[i] < buf[j]) sums[k] = buf[i++];
      else sums[k] = buf[j++];
    }
    for (; i < n2; ++k) sums[k] = buf[i++];
    for (; j < n; ++k) sums[k] = buf[j++];

    return a + b + c;
  }
};
