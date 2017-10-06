class Solution
{
 public:
  bool isPalindrome(string s)
  {
    for (int i = 0, j = s.size() - 1; i < j;) {
      if (!isalnum(s[i]))
        ++i;
      else if (!isalnum(s[j]))
        --j;
      else if (tolower(s[i++]) != tolower(s[j--]))
        return false;
    }
    return true;
  }
};
