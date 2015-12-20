class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ret;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      int t = digits[i] + carry;
      ret.push_back(t % 10);
      carry = t / 10;
    }
    if (carry) ret.push_back(carry);

    reverse(ret.begin(), ret.end());

    return ret;
  }
};
