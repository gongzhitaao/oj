class Solution
{
 public:
  string frequencySort(string s)
  {
    int n = s.size();
    vector<string> sorted(n+1, "");
    vector<int> cnt(CHAR_MAX, 0);
    for (char c : s) ++cnt[c];
    for (int i = 0; i < CHAR_MAX; ++i)
      sorted[cnt[i]] += string(cnt[i], i);
    string ret;
    for (string& e : sorted) ret = e + ret;
    return ret;
  }
};
