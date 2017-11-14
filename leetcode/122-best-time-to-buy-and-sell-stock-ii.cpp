class Solution
{
 public:
  int maxProfit(vector<int>& prices)
  {
    int p = 0, n = prices.size();
    for (int i = 0; i < n - 1; ++i)
      if (prices[i + 1] > prices[i]) p += prices[i + 1] - prices[i];
    return p;
  }
};
