class Solution
{
 public:
  string multiply(string num1, string num2)
  {
    if (num1.size() > num2.size())
      return multiply(num2, num1);

    if ("0" == num1 || "0" == num2)
      return "0";

    int n1 = num1.size(), n2 = num2.size();
    string ret(n1+n2, '0');

    for (int i = n1-1, k; i >= 0; --i) {
      int carry = 0, a = num1[i]-'0';
      k = n2 + i;
      for (int j = n2-1; j >= 0; --j, --k) {
        int tmp = a * (num2[j]-'0') + ret[k]-'0' + carry;
        carry = tmp / 10;
        ret[k] = (tmp % 10) + '0';
      }
      ret[k] += carry;
      cout << ret << endl;
    }

    int pos = 0;
    for (; '0' == ret[pos]; ++pos) /* empty */;

    return ret.substr(pos);
  }
};
