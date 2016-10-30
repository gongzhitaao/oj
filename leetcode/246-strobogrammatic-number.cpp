class Solution
{
 public:
  bool isStrobogrammatic(string num)
  {
    // 1 6 8 9 0
    int n = num.size();
    for (int i = 0; i < (n+1)/2; ++i) {
      if (!((('0' == num[i] || '1' == num[i] || '8' == num[i]) &&
             num[i] == num[n-i-1]) ||
            ('6' == num[i] && '9' == num[n-i-1]) ||
            ('9' == num[i] && '6' == num[n-i-1])))
        return false;
    }
    return true;
  }
};
