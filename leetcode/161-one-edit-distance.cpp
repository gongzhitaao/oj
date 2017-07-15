class Solution
{
 public:
  bool isOneEditDistance(string s, string t)
  {
    int slen = s.size(), tlen = t.size();
    int n = min(slen, tlen);
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[i]) {
        if (slen == tlen)
          return s.substr(i+1) == t.substr(i+1);
        if (slen < tlen)
          return s.substr(i) == t.substr(i+1);
        return s.substr(i+1) == t.substr(i);
      }
    }

    return abs(slen - tlen) == 1;
  }
};
