class Solution
{
 public:
  int coinChange(vector<int>& coins, int amount)
  {
    sort(coins.begin(), coins.end());
    vector<int> cnt(amount + 1, -1);
    cnt[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int c : coins) {
        if (c > i) break;
        if (cnt[i - c] >= 0 && (cnt[i] < 0 || cnt[i - c] + 1 < cnt[i]))
          cnt[i] = cnt[i - c] + 1;
      }
    }
    return cnt[amount];
  }
};
