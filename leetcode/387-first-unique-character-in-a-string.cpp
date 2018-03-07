class Solution
{
 public:
  int firstUniqChar(string s)
  {
    vector<int> cnt(128, 0);
    vector<int> pos(128, 0);
    int total = 0;
    for (int i = 0; i < s.size(); ++i)
      if (1 == ++cnt[s[i]]) pos[total++] = i;
    for (int i = 0; i < total; ++i)
      if (1 == cnt[s[pos[i]]]) return pos[i];
    return -1;
  }
};
