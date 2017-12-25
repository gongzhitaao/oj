class Solution
{
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
  {
    int sum = 0, n = gas.size();
    for (int i = 0, j = 0; i < n;) {
      sum += gas[j] - cost[j];
      j = (j + 1) % n;
      if (sum < 0) {
        if (j <= i) return -1;
        i = j;
        sum = 0;
      } else if (j == i)
        return i;
    }
    return -1;
  }
};
