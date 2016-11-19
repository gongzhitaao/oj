class Solution
{
 public:
  char findTheDifference(string s, string t)
  {
    vector<int> cnt(128, 0);
    for (char c : s) ++cnt[c];
    for (char c : t)
      if (--cnt[c] < 0) return c;
    return 0;
  }
};
