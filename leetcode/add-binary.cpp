class Solution {
public:
  string addBinary(string a, string b) {
    string sum = "";
    array<int, 4> s = {0, 1, 0, 1};
    array<int, 4> c = {0, 0, 1, 1};

    int carry = 0, i;
    int m = a.size(), n = b.size();
    for (i = 0; i < m && i < n; ++i) {
      int t = (a[m - i - 1] - '0') + (b[n - i - 1] - '0') + carry;
      sum = to_string(s[t]) + sum;
      carry = c[t];
    }

    for (int j = i; j < m; ++j) {
      int t = (a[m - j - 1] - '0') + carry;
      sum = to_string(s[t]) + sum;
      carry = c[t];
    }

    for (int j = i; j < n; ++j) {
      int t = (b[n - j - 1] - '0') + carry;
      sum = to_string(s[t]) + sum;
      carry = c[t];
    }

    return carry ? to_string(carry) + sum : sum;
  }
};
