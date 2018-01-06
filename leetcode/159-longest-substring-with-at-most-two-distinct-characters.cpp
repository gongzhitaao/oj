class Solution
{
 public:
  int lengthOfLongestSubstringTwoDistinct(string s)
  {
    vector<int> cnt(128, 0);
    int total = 2, len = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (1 == ++cnt[s[j]]) --total;
      for (; total < 0; ++i)
        if (0 == --cnt[s[i]]) ++total;
      if (j - i + 1 > len) len = j - i + 1;
    }
    return len;
  }
};
