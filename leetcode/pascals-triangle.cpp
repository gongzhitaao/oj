class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ret;

    if (numRows <= 0) return ret;
    if (1 == numRows) {
      ret.push_back({1});
    } else {
      ret.push_back({1});
      for (int i = 1; i < numRows; ++i) {
        vector<int> v;
        v.push_back(1);
        for (int j = 0; j < i - 1; ++j)
          v.push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
        v.push_back(1);
        ret.push_back(v);
      }
    }

    return ret;
  }
};
