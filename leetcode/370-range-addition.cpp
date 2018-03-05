class Solution
{
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
  {
    vector<int> ret(length, 0);
    for (auto& u : updates) {
      if (u[0] > 0) ret[u[0] - 1] -= u[2];
      ret[u[1]] += u[2];
    }
    for (int i = length - 1, inc = 0; i >= 0; inc = ret[i--]) ret[i] += inc;
    return ret;
  }
};
