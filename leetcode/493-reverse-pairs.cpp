class Solution
{
 public:
  int reversePairs(vector<int>& nums)
  {
    if (nums.empty()) return 0;
    vector<long long> tmp(nums.size(), 0);
    copy(nums.begin(), nums.end(), tmp.begin());
    return mergecnt(tmp, 0, tmp.size() - 1);
  }

  int mergecnt(vector<long long>& nums, int lo, int hi)
  {
    if (lo == hi) return 0;

    int mi = lo + (hi - lo) / 2;
    int cl = mergecnt(nums, lo, mi);
    int cr = mergecnt(nums, mi + 1, hi);

    int cm = 0, i, j, k;
    for (i = lo, j = mi + 1; i <= mi; ++i) {
      for (; j <= hi && nums[i] > 2 * nums[j]; ++j);
      cm += j - mi - 1;
    }

    vector<long long> tmp(hi - lo + 1, 0);
    for (i = lo, j = mi + 1, k = 0; i <= mi && j <= hi; ++k) {
      if (nums[i] < nums[j]) tmp[k] = nums[i++];
      else tmp[k] = nums[j++];
    }
    for (; i <= mi; ++k, ++i) tmp[k] = nums[i];
    for (; j <= hi; ++k, ++j) tmp[k] = nums[j];
    copy(tmp.begin(), tmp.end(), nums.begin() + lo);

    return cl + cm + cr;
  }
};
