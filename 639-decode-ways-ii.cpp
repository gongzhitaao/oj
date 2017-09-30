class Solution
{
 public:
  int numDecodings(string s)
  {
    if (s.empty()) return 0;

    const int n = 1000000007;

    s = "xx" + s;
    long long k2 = 1, k1 = 1, k = 0;

    for (int i = 2; i < s.size(); ++i) {
      k = 0;
      if ('*' == s[i]) {
        if ('*' == s[i - 1] || '1' == s[i - 1]) k = (k + 9 * k2) % n;
        if ('*' == s[i - 1] || '2' == s[i - 1]) k = (k + 6 * k2) % n;
        k = (k + 9 * k1) % n;
      } else {
        if ('*' == s[i - 1] || '1' == s[i - 1]) k = (k + k2) % n;
        if (('*' == s[i - 1] || '2' == s[i - 1]) && s[i] <= '6')
          k = (k + k2) % n;
        if ('0' != s[i]) k = (k + k1) % n;
      }
      k2 = k1, k1 = k;
    }

    return k;
  }
};
