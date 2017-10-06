class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    if (prices.empty()) return 0;

    int maxprof = 0;
    int minprice = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] <= minprice)
        minprice = prices[i];
      else if (prices[i] - minprice > maxprof)
        maxprof = prices[i] - minprice;
    }

    return maxprof;
  }
};
