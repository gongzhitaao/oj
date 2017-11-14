class Solution
{
 public:
  int maxProfit(int k, vector<int>& prices)
  {
    const int n = prices.size();
    vector<long long> sell(n + 1, 0), tmp(n + 1, 0);
    if (k > n) k = n;
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
