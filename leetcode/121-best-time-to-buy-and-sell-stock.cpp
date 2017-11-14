class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    long long hold = numeric_limits<int>::min(), sell = 0;
    for (int i = 0; i < prices.size(); ++i) {
      sell = max(sell, hold + prices[i]);
      hold = max(hold, 0LL - prices[i]);
    }
    return sell;
  }
};
