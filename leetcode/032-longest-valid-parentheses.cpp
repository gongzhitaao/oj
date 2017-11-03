class Solution
{
 public:
  int longestValidParentheses(string s)
  {
    int maxlen = 0;
    if (s.size() < 2) return maxlen;

    vector<int> len(s.size(), 0);
    if ('(' == s[0] && ')' == s[1]) maxlen = len[1] = 2;

    for (int i = 2; i < s.size(); ++i) {
      if ('(' == s[i]) continue;
      if ('(' == s[i - 1]) {
        len[i] = 2 + len[i - 2];
      } else {
        int j = i - len[i - 1];
        if (j > 0 && '(' == s[j - 1]) {
          len[i] = 2 + len[i - 1];
          if (j > 1) len[i] += len[j - 2];
        }
      }
      if (len[i] > maxlen) maxlen = len[i];
    }
    return maxlen;
  }
};
