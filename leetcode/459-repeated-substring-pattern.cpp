class Solution
{
 public:
  bool repeatedSubstringPattern(string str)
  {
    int n = str.size();
    for (int i = 2, j; n / i >= 1; ++i) {
      if (n % i) continue;
      int len = n / i;
      string s = str.substr(0, len);
      for (j = 1; j < i; ++j)
        if (str.substr(j*len, len) != s) break;
      if (j == i) return true;
    }
    return false;
  }
};
