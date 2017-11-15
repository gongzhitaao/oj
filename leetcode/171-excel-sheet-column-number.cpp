class Solution
{
 public:
  int titleToNumber(string s)
  {
    int ret = 0;
    for (char ch : s)
      ret = ret * 26 + ch - 'A' + 1;
    return ret;
  }
};
