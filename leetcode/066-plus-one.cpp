class Solution
{
 public:
  vector<int> plusOne(vector<int>& digits)
  {
    vector<int> ret;
    int carry = 1;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      int sum = *it + carry;
      carry = sum / 10;
      sum = sum % 10;
      ret.push_back(sum);
    }
    if (carry) ret.push_back(carry);
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
