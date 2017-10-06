class Solution
{
 public:
  bool isOneEditDistance(string s, string t)
  {
    if (s.size() > t.size()) swap(s, t);

    if (t.size() - s.size() > 1) return false;

    if (s.size() == t.size()) {
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        cnt += s[i] != t[i];
        if (cnt > 1) return false;
      }
      return 1 == cnt;
    }

    for (int i = 0, j = 0; i < s.size(); ++j) {
      i += s[i] == t[j];
      if (j - i > 1) return false;
    }
    return true;
  }
};
