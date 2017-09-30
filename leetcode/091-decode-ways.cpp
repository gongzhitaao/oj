class Solution
{
 public:
  int numDecodings(string s)
  {
    if (s.empty()) return 0;

    s = "xx" + s;
    int k2 = 1, k1 = 1, k = 0;

    for (int i = 2; i < s.size(); ++i) {
      k = 0;
      if ('1' == s[i - 1] || ('2' == s[i - 1] && s[i] <= '6')) k += k2;
      if (s[i] > '0') k += k1;
      k2 = k1, k1 = k;
    }
    return k;
  }
};
