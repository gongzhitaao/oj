class Solution
{
 public:
  int numDecodings(string s)
  {
    if (s.empty()) return 0;

    s = "xx" + s;
    vector<int> cnt(s.size(), 0);
    cnt[0] = cnt[1] = 1;

    for (int i = 2; i < s.size(); ++i) {
      if ('1' == s[i - 1] || ('2' == s[i - 1] && s[i] <= '6'))
        cnt[i] += cnt[i - 2];
      if (s[i] > '0') cnt[i] += cnt[i - 1];
    }
    return cnt.back();
  }
};
