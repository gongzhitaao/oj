class Solution
{
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper)
  {
    if (nums.empty()) return 0;
    const int n = nums.size();

    vector<long long> sums(n + 1, 0);
    for (int i = 0; i < n; ++i) sums[i + 1] = nums[i] + sums[i];

    return mergecnt(sums, lower, upper, 0, n);
  }

  int mergecnt(vector<long long>& sums, int lower, int upper, int lo, int hi)
  {
    if (lo == hi) return 0;

    int mi = lo + (hi - lo) / 2;
    int cl = mergecnt(sums, lower, upper, lo, mi);
    int cr = mergecnt(sums, lower, upper, mi + 1, hi);

    int cm = 0, i, j, k;
    for (k = lo, i = j = mi + 1; k <= mi; ++k) {
      for (; i <= hi && sums[i] - sums[k] < lower; ++i);
      for (; j <= hi && sums[j] - sums[k] <= upper; ++j);
      cm += j - i;
    }

    vector<long long> tmp(hi - lo + 1, 0);
    for (i = lo, j = mi + 1, k = 0; i <= mi && j <= hi; ++k) {
      if (sums[i] < sums[j]) tmp[k] = sums[i++];
      else tmp[k] = sums[j++];
    }
    for (; i <= mi; ++k, ++i) tmp[k] = sums[i];
    for (; j <= hi; ++k, ++j) tmp[k] = sums[j];

    copy(tmp.begin(), tmp.end(), sums.begin() + lo);

    return cl + cm + cr;
  }
};
