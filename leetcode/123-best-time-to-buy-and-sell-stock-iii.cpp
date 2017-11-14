class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    const int MIN = numeric_limits<int>::min();
    vector<long long> sell(3, 0), tmp_sell(3, 0);
    vector<long long> hold(3, MIN), tmp_hold(3, MIN);
    for (int i = 1; i <= prices.size(); ++i) {
      swap(sell, tmp_sell);
      swap(hold, tmp_hold);
      for (int j = 1; j <= 2; ++j) {
        sell[j] = max(tmp_sell[j], tmp_hold[j] + prices[i - 1]);
        hold[j] = max(tmp_hold[j], tmp_sell[j - 1] - prices[i - 1]);
      }
    }
    return max(sell[1], sell[2]);
  }
};
