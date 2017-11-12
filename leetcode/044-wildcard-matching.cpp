class Solution
{
 public:
  bool isMatch(string s, string p)
  {
    int i = 0, j = 0;
    for (int i0 = -1, j0 = -1; i < s.size(); ++j) {
      if (j == p.size()) {
        if (i0 < 0) return false;
        i = ++i0;
        j = j0;
      } else if ('*' == p[j]) {
        i0 = i;
        j0 = j;
      } else if (s[i++] != p[j] && '?' != p[j]) {
        if (i0 < 0) return false;
        i = ++i0;
        j = j0;
      }
    }

    for (; j < p.size() && '*' == p[j]; ++j)
      ;

    return s.size() == i && p.size() == j;
  }
};
