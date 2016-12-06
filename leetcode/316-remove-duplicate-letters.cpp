class Solution
{
 public:
  string removeDuplicateLetters(string s)
  {
    vector<int> cnt(128, 0);
    for (char ch : s) ++cnt[ch];
    return doit(s, cnt);
  }

  string doit(string s, vector<int>& cnt)
  {
    int minpos = -1, i;
    for (i = 0; i < s.size(); ++i) {
      if (!cnt[s[i]]) continue;
      if (minpos < 0 || s[i] < s[minpos]) minpos = i;
      if (0 == --cnt[s[i]]) break;
    }
    if (minpos < 0) return "";
    ++cnt[s[i]];
    cnt[s[minpos]] = 0;
    for (int j = minpos+1; j < i; ++j)
      if (cnt[s[j]]) ++cnt[s[j]];
    return s[minpos] + doit(s.substr(minpos+1), cnt);
  }
};
