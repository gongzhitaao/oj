class Solution
{
 public:
  string rearrangeString(string str, int k)
  {
    vector<int> cnt(26, 0), pos(26, -k);
    for (char c : str) ++cnt[c - 'a'];

    string ret;
    for (int i = 0, maxcnt, maxpos; i < str.size(); ++i) {
      maxcnt = 1, maxpos = -1;
      for (int j = 0; j < 26; ++j)
        if (pos[j] <= i - k && cnt[j] >= maxcnt) maxpos = j, maxcnt = cnt[j];
      if (maxpos < 0) return "";

      ret += char(maxpos + 'a');
      --cnt[maxpos];
      pos[maxpos] = i;
    }
    return ret;
  }
};
