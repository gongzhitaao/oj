class Solution
{
 public:
  string countAndSay(int n)
  {
    string ret = "1#";
    for (int i = 0, j = 0, k = 0; i < n - 1; ++i) {
      string tmp;
      for (j = 1, k = 1; j < ret.size(); ++j) {
        if (ret[j] == ret[j - 1])
          ++k;
        else {
          tmp += to_string(10 * k + ret[j - 1] - '0');
          k = 1;
        }
      }
      ret = tmp + "#";
    }
    ret.pop_back();
    return ret;
  }
};
