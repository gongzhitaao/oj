class Solution
{
 public:
  bool splitArray(vector<int>& nums)
  {
    const int n = nums.size();

    vector<int> sum(n, 0);
    sum[0] = nums[0];
    for (int i = 1; i < n; ++i)
      sum[i] = sum[i - 1] + nums[i];

    for (int i = 3; i < n - 3; ++i) {
      unordered_set<int> qs;
      for (int j = 1; j < i - 1; ++j) {
        if (sum[j - 1] == sum[i - 1] - sum[j])
          qs.insert(sum[j - 1]);
      }

      for (int j = i + 2; j < n - 1; ++j) {
        if (sum[j - 1] - sum[i] == sum[n - 1] - sum[j] &&
            qs.find(sum[n - 1] - sum[j]) != qs.end())
          return true;
      }
    }

    return false;
  }
};
