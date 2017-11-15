class Solution
{
 public:
  string convertToTitle(int n)
  {
    string ret;
    for (int i = n; i; i = (i - 1) / 26)
      ret += ((i - 1) % 26) + 'A';
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
