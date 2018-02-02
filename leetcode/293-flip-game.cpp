class Solution
{
 public:
  vector<string> generatePossibleNextMoves(string s)
  {
    vector<string> ret;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
      if ('+' == s[i] and s[i] == s[i + 1]) {
        string ss = s;
        ss[i] = ss[i + 1] = '-';
        ret.push_back(ss);
      }
    }
    return ret;
  }
};
