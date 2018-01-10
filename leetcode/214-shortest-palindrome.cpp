class Solution
{
 public:
  string shortestPalindrome(string s)
  {
    int i, j, k;
    for (i = 0, j = s.size() - 1, k = s.size() - 1; i < k; ) {
      if (s[i] != s[k]) i = 0, k = --j;
      else ++i, --k;
    }
    string prefix = s.substr(2 * k + i - k + 1);
    reverse(prefix.begin(), prefix.end());
    return prefix + s;
  }
};
