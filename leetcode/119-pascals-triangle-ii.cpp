class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> ret;
    ret.push_back(1);
    for (int i = 0; i < rowIndex; ++i) {
      ret.push_back((long long)ret[i] * (rowIndex - i) / (i + 1));
    }
    return ret;
  }
};
