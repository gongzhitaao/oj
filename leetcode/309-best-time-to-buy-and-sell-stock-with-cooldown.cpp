class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;

    int n = 0, y = 0, nn = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int t = y;
      y = max(y, nn) + prices[i] - prices[i - 1];
      nn = n;
      n = max(n, t);
    }

    return max(n, y);
  }
};
