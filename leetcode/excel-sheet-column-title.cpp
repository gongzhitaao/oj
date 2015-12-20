class Solution {
public:
  string convertToTitle(int n) {
    string ret = "";
    for (int i = n; i ; i = (i - 1) / 26) {
      int j = (i - 1) % 26;
      ret = (char)(j + 'A') + ret;
    }

    return ret;
  }
};
