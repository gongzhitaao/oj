class Solution
{
 public:
  int coinChange(vector<int>& coins, int amount)
  {
    if (coins.empty()) return -1;
    vector<int> cnt(amount + 1, -1);
    cnt[0] = 0;
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = 1; j <= amount; ++j) {
        int end = j / coins[i];
        for (int k = 0; k <= end; ++k) {
          int pre = cnt[j - k * coins[i]];
          if (pre >= 0 && (cnt[j] < 0 || pre + k < cnt[j])) cnt[j] = pre + k;
          if (cnt[j] >= 0 && cnt[j] < end) end = cnt[j];
        }
      }
    }
    return cnt[amount];
  }
};
