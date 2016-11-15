class Solution
{
 public:
  string addStrings(string num1, string num2)
  {
    string sum;
    int carry = 0, i, j;
    for (i = num1.size()-1, j = num2.size()-1; i >= 0 && j >= 0;
         --i, --j) {
      int tmp = carry + num1[i] - '0' + num2[j] - '0';
      carry = tmp / 10;
      sum = char(tmp % 10 + '0') + sum;
    }
    for (; i >= 0; --i) {
      int tmp = carry + num1[i] - '0';
      carry = tmp / 10;
      sum = char(tmp % 10 + '0') + sum;
    }
    for (; j >= 0; --j) {
      int tmp = carry + num2[j] - '0';
      carry = tmp / 10;
      sum = char(tmp % 10 + '0') + sum;
    }
    if (carry) sum = char(carry + '0') + sum;
    return sum;
  }
};
