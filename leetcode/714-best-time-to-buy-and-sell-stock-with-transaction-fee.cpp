class Solution
{
 public:
  int maxProfit(vector<int>& prices, int fee)
  {
    long long hold = numeric_limits<int>::min(), sell = 0;
    for (int i = 0; i < prices.size(); ++i) {
      long long tmp = sell;
      sell = max(sell, hold + prices[i] - fee);
      hold = max(hold, tmp - prices[i]);
    }
    return max(hold, sell);
  }
};
