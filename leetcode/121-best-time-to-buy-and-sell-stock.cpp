class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int small = prices[0];
    int ret = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < small)
        small = prices[i];
      else if (prices[i] - small > ret)
        ret = prices[i] - small;
    }

    return ret;
  }
};
