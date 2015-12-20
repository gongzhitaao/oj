class Solution {
public:
  int lengthOfLastWord(string s) {
    int end;
    for (end = s.size() - 1; end >= 0 && ' ' == s[end]; --end) ;

    int i;
    for (i = end; i >= 0; --i)
      if (' ' == s[i]) return end - i;

    return end - i;
  }
};
