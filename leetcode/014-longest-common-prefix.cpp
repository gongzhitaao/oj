class Solution
{
 public:
  string longestCommonPrefix(vector<string>& strs)
  {
    if (strs.empty()) return "";

    string ret;
    for (int i = 0; /* empty */; ++i) {
      if (strs[0].size() == i) break;
      const char c = strs[0][i];
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j].size() == i || c != strs[j][i]) {
          i = -1;
          break;
        }
      }

      if (i >= 0) ret += c;
      else break;
    }
    return ret;
  }
};
