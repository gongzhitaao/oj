class Solution
{
 public:
  int lengthOfLongestSubstring(string s)
  {
    vector<int> pos(128, -1);
    int maxlen = 0;
    for (int i = 0, start = -1; i < s.size(); ++i) {
      if (pos[s[i]] > start) start = pos[s[i]];
      if (i - start > maxlen) maxlen = i - start;
      pos[s[i]] = i;
    }
    return maxlen;
  }
};
