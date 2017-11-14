class Solution
{
 public:
  bool validPalindrome(string s)
  {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
      if (s[i] != s[j])
        return pal(s, i + 1, j) || pal(s, i, j - 1);
    return true;
  }

  bool pal(string& s, int i, int j)
  {
    for (; i < j; ++i, --j)
      if (s[i] != s[j]) return false;
    return true;
  }
};
