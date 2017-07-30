class Solution {
public:
  string countAndSay(int n) {
    string ret = "1";
    for (int i = 0; i < n - 1; ++i) {
      string t = "";
      char c = ret[0];
      int cnt = 1;
      for (int j = 1; j < ret.size(); ++j) {
        if (ret[j] == c) ++cnt;
        else {
          t += to_string(cnt) + c;
          c = ret[j];
          cnt = 1;
        }
      }
      ret = t + to_string(cnt) + c;
    }

    return ret;
  }
};
