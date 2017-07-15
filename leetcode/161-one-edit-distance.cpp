class Solution
{
 public:
  bool isOneEditDistance(string s, string t)
  {
    int slen = s.size(), tlen = t.size();

    if (slen == tlen) {
      int cnt = 0;
      for (int i = 0; i < slen; ++i)
        if ((cnt += s[i] != t[i]) > 1)
          return false;
      return 1 == cnt;
    }

    if (abs(slen-tlen) > 1) return false;

    vector<vector<int>> len(2, vector<int>(tlen+1, 0));
    for (int i = 1, k; i < slen+1; ++i) {
      k = i & 1;
      for (int j = 1; j < tlen+1; ++j)
        if (s[i-1] == t[j-1]) len[k][j] = len[1-k][j-1] + 1;
        else len[k][j] = max(len[1-k][j], len[k][j-1]);
    }

    return len[slen&1][tlen] == slen || len[slen&1][tlen] == tlen;
  }
};
