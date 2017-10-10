class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    vector<int> cnt(128, 0);
    int maxlen = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      ++cnt[s[j]];
      for (; i < j && cnt[s[j]] > 1; --cnt[s[i++]])
        ;
      if (j - i + 1 > maxlen) maxlen = j - i + 1;
    }
    return maxlen;
  }
};
