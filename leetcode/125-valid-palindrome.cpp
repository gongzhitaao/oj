class Solution {
public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ) {
      char a = tolower(s[i]), b = tolower(s[j]);

      if (isalnum(a) && isalnum(b)) {
        if (a != b) return false;
        ++i, --j;
      } else {
        if (!isalnum(a)) ++i;
        if (!isalnum(b)) --j;
      }
    }

    return true;
  }
};
