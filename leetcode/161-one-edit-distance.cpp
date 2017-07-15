class Solution
{
 public:
  bool isOneEditDistance(string s, string t)
  {
    int slen = s.size(), tlen = t.size();

    if (slen == tlen) {
      int cnt = 0;
      for (int i = 0; i < slen; ++i)
        if ((cnt += s[i] != t[i]) > 1)
          return false;
      return 1 == cnt;
    }

    string a, b;
    if (slen + 1 == tlen)
      a = s, b = t;
    else if (tlen + 1 == slen)
      a = t, b = s;
    else return false;

    for (int i = 0; i < b.size(); ++i)
      if (b.substr(0, i) + b.substr(i+1) == a)
        return true;
    return false;

  }
};
