class Solution
{
 public:
  vector<int> countSmaller(vector<int>& nums)
  {
    const int n = nums.size();
    vector<int> cnt(n, 0), idx(n, 0);
    for (int i = 0; i < nums.size(); ++i)
      idx[i] = i;
    mergesort(nums, cnt, idx, 0, n - 1);
    return cnt;
  }

  void mergesort(vector<int>& nums, vector<int>& cnt, vector<int>& idx, int lo,
                 int hi)
  {
    if (lo >= hi) return;

    int mi = lo + (hi - lo) / 2;
    mergesort(nums, cnt, idx, lo, mi);
    mergesort(nums, cnt, idx, mi + 1, hi);

    vector<int> work(hi - lo + 1, 0), idx1(hi - lo + 1, 0);

    int i, j, k, c;
    for (c = 0, i = lo, j = mi + 1, k = 0; i <= mi && j <= hi; ++k) {
      if (nums[i] <= nums[j])
        work[k] = nums[i], idx1[k] = idx[i], ++i, cnt[idx1[k]] += c;
      else
        work[k] = nums[j], idx1[k] = idx[j], ++j, ++c;
    }
    for (; i <= mi; ++k, ++i)
      work[k] = nums[i], idx1[k] = idx[i], cnt[idx1[k]] += c;
    for (; j <= hi; ++k, ++j)
      work[k] = nums[j], idx1[k] = idx[j];

    copy(work.begin(), work.end(), nums.begin() + lo);
    copy(idx1.begin(), idx1.end(), idx.begin() + lo);
  }
};
