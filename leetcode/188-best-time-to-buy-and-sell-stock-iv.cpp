class Solution
{
 public:
  int maxProfit(int k, vector<int>& prices)
  {
    const int n = prices.size();

    if (k >= n / 2) {
      int p = 0;
      for (int i = 0; i < n - 1; ++i)
        if (prices[i + 1] > prices[i]) p += prices[i + 1] - prices[i];
      return p;
    }

    vector<long long> sell(n + 1, 0), tmp(n + 1, 0);
    for (int i = 1; i <= k; ++i) {
      long long hold = numeric_limits<int>::min();;
      swap(sell, tmp);
      for (int j = 1; j <= n; ++j) {
        sell[j] = max(sell[j - 1], hold + prices[j - 1]);
        hold = max(hold, tmp[j - 1] - prices[j - 1]);
      }
    }
    return *max_element(sell.begin(), sell.end());
  }
};
