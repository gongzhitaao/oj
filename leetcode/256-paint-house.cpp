class Solution
{
 public:
  int minCost(vector<vector<int>>& costs)
  {
    if (costs.empty()) return 0;
    vector<int> cost = costs[0], old = costs[0];

    for (int i = 1; i < costs.size(); ++i) {
      swap(cost, old);

      cost[0] = costs[i][0] + min(old[1], old[2]);
      cost[1] = costs[i][1] + min(old[0], old[2]);
      cost[2] = costs[i][2] + min(old[0], old[1]);
    }

    return min(cost[0], min(cost[1], cost[2]));
  }
};
