class Solution
{
 public:
  string multiply(string num1, string num2)
  {
    if (num1.size() < num2.size()) swap(num1, num2);

    if ("0" == num2 || "0" == num1) return "0";
    if ("1" == num2) return num1;

    string res(num1.size() + num2.size() + 1, '0');
    for (int i = num2.size() - 1, j, k; i >= 0; --i) {
      int carry = 0;
      for (j = num1.size() - 1, k = num2.size() - 1 - i; j >= 0; --j, ++k) {
        int out = carry + (num2[i] - '0') * (num1[j] - '0') + res[k] - '0';
        res[k] = out % 10 + '0';
        carry = out / 10;
      }

      for (; carry; ++k) {
        int out = carry + res[k] - '0';
        res[k] = out % 10 + '0';
        carry = out / 10;
      }
    }

    int p = res.size() - 1;
    for (; p >= 0 && '0' == res[p]; --p)
      ;
    res = res.substr(0, p + 1);
    reverse(res.begin(), res.end());

    return res;
  }
};
