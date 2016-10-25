class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k)
  {
    if (k <= 0) return 0;
    if (k >= s.size()) return s.size();

    int n = s.size();
    unordered_map<char, int> cnt;
    int maxlen = 0;
    for (int i = 0, j = 0; j < n; ++j) {
      cnt[s[j]]++;
      while (cnt.size() > k) {
        char c = s[i++];
        if (0 == --cnt[c])
          cnt.erase(c);
      }
      if (j - i + 1 > maxlen)
        maxlen = j - i + 1;
    }
    return maxlen;
  }
};
