class Solution
{
 public:
  int lengthOfLongestSubstringTwoDistinct(string s)
  {
    int n = s.size();
    if (!n) return 0;

    unordered_map<char, int> buf;
    int prelen = 0, maxlen = 0;
    for (int i = 0; i < n; ++i) {
      if (buf.find(s[i]) == buf.end() && 2 == buf.size()) {
        for (auto ch : buf) {
          if (ch.first != s[i-1]) {
            prelen = i - ch.second;
            buf.erase(ch.first);
            break;
          }
        }
      } else ++prelen;
      buf[s[i]] = i;
      if (prelen > maxlen) maxlen = prelen;
    }
    return maxlen;
  }
};
