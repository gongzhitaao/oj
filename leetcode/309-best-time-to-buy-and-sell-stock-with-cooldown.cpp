class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    long long hold = numeric_limits<int>::min(), sell[2] = {0, 0};
    for (int i = 0; i < prices.size(); ++i) {
      long long tmp = sell[i % 2];
      sell[i % 2] = max(sell[1 - (i % 2)], hold + prices[i]);
      hold = max(hold, tmp - prices[i]);
    }
    return max(sell[0], sell[1]);
  }
};
