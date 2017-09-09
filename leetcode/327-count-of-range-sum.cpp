class Solution
{
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper)
  {
    return mergecnt(nums, lower, upper, 0, nums.size() - 1);
  }

  int mergecnt(vector<int>& nums, int lower, int upper, int lo, int hi)
  {
    if (lo > hi) return 0;
    if (lo == hi) return lower <= nums[lo] && nums[lo] <= upper;

    int mi = lo + (hi - lo) / 2;

    vector<long long> lsum;
    for (long long i = mi, sum = 0; i >= lo; --i)
      lsum.push_back(sum += nums[i]);
    sort(lsum.begin(), lsum.end());

    int cnt = 0;
    for (long long j = mi + 1, sum = 0; j <= hi; ++j) {
      sum += nums[j];
      auto start = lower_bound(lsum.begin(), lsum.end(), lower - sum);
      auto end = upper_bound(lsum.begin(), lsum.end(), upper - sum);
      cnt += distance(start, end);
    }

    int lcnt = mergecnt(nums, lower, upper, lo, mi);
    int rcnt = mergecnt(nums, lower, upper, mi + 1, hi);

    return cnt + lcnt + rcnt;
  }
};
