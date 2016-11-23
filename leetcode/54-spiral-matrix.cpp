class Solution
{
 public:
  vector<int> spiralOrder(vector<vector<int> >& matrix)
  {
    vector<int> ret;
    if (matrix.empty() || matrix[0].empty()) return ret;

    vector<int> sz{matrix[0].size(), matrix.size()};
    const int n = sz[0] * sz[1];
    const vector<int> dir = {0, 1, 0, -1, 0};
    const vector<int> trn = {1, -1, -1, 1, 1};
    const vector<int> chg = {-1, 0};
    for (int d = 0, i = 0, j = 0; ret.size() < n ; d = (d+1)%4) {
      for (int c = 0; c++ < sz[d%2]; i += dir[d], j += dir[d+1])
        ret.push_back(matrix[i][j]);
      i += trn[d], j += trn[d+1];
      sz[1] += chg[d%2];
      sz[0] += chg[(d+1)%2];
    }
    return ret;
  }
};
