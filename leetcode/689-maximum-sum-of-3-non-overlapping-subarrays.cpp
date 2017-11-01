class Solution
{
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
  {
    const int n = nums.size();

    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];

    vector<int> lo(n, 0);
    for (int i = k - 1, maxsum = sum[k]; i < n - 2 * k; ++i) {
      if (sum[i + 1] - sum[i - k + 1] > maxsum)
        lo[i] = i - k + 1, maxsum = sum[i + 1] - sum[i - k + 1];
      else lo[i] = lo[i - 1];
    }

    vector<int> hi(n, n - k);
    for (int i = n - k - 1, maxsum = sum[n] - sum[n - k]; i >= 2 * k; --i) {
      if (sum[i + k] - sum[i] >= maxsum)
        hi[i] = i, maxsum = sum[i + k] - sum[i];
      else hi[i] = hi[i + 1];
    }

    int maxsum = 0;
    vector<int> ret;
    for (int i = k; i < n - 2 * k + 1; ++i) {
      int a = lo[i - 1], b = hi[i + k];
      int cur = sum[a + k] - sum[a] + sum[i + k] - sum[i] + sum[b + k] - sum[b];
      if (cur > maxsum) {
        maxsum = cur;
        ret = {a, i, b};
      }
    }

    return ret;
  }
};
