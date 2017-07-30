class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int p = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
      int t = prices[i + 1] - prices[i];
      if (t > 0) p += t;
    }

    return p;
  }
};
