class Solution
{
 public:
  int totalHammingDistance(vector<int>& nums)
  {
    vector<int> cnt(32, 0);
    for (int n : nums) {
      for (int i = 0; n; ++i, n >>= 1)
        cnt[i] += (n & 1);
    }
    int sum = 0;
    int n = nums.size();
    for (int k : cnt)
      sum += k * (n - k);
    return sum;
  }
};
