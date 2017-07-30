class Solution {
 public:
  string reverseString(string s) {
    for (int i = 0, j = s.size()-1; i < j; ++i, --j)
      std::swap(s[i], s[j]);
    return s;
  }
};
