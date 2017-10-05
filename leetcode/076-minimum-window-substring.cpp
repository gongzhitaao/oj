class Solution
{
 public:
  string minWindow(string s, string t)
  {
    vector<int> cnt(128, 0);
    for (char ch : t) ++cnt[ch];

    int left = t.size(), i0 = 0, len = s.size() + 1;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (--cnt[s[j]] >= 0) --left;
      for (; 0 == left; ++i) {
        if (j - i + 1 < len)
          i0 = i, len = j - i + 1;
        if (cnt[s[i]]++ == 0) ++left;
      }
    }

    return len > s.size() ? "" : s.substr(i0, len);
  }
};
