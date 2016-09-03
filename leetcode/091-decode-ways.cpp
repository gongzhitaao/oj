class Solution {
 public:
  int numDecodings(string s)
  {
    if (s.empty()) return 0;

    int a = 1, b = s[0] != '0';
    for (int i = 1; i < s.size(); ++i) {
      int n0 = s[i] - '0';
      int n1 = (s[i - 1] - '0') * 10 + n0;

      int c = 0;
      if (0 < n0) c += b;
      if (9 < n1 && n1 <= 26) c += a;

      a = b, b = c;
    }

    return b;
  }
};
