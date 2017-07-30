class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ret = {0};

    int bit = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = ret.size() - 1; j >= 0; --j)
        ret.push_back(bit | ret[j]);
      bit <<= 1;
    }

    return ret;
  }
};
