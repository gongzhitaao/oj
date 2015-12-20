class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = "";
    for (int p = 0; true; ++p) {
      string &str = strs[0];
      if (p >= str.size()) goto end;

      char c = str[p];
      for (int i = 1; i < strs.size(); ++i) {
        if (c != strs[i][p]) goto end;
      }

      prefix += c;
    }

  end:
    return prefix;
  }
};
