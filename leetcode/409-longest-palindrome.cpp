class Solution
{
 public:
  int longestPalindrome(string s)
  {
    vector<int> cnt(128, 0);
    for (char c : s) ++cnt[c];
    int len = 0;
    for (int i : cnt) len += 0xFFFFFFFE & i;
    if (len < s.size()) ++len;
    return len;
  }
};
