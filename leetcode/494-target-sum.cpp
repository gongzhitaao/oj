class Solution
{
 public:
  int findTargetSumWays(vector<int>& nums, int S)
  {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if ((sum + S) % 2 || sum < S) return 0;
    int target = (sum + S) / 2;

    vector<int> cnt(target + 1, 0);
    cnt[0] = 1;
    for (int n : nums)
      for (int i = target; i >= n; --i)
        cnt[i] += cnt[i - n];
    return cnt.back();
  }
};
