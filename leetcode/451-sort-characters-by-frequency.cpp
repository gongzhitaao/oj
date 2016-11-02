class Solution
{
 public:
  string frequencySort(string s)
  {
    int n = numeric_limits<char>::max() + 1;
    vector<int> cnt(n, 0);
    for (char c : s) ++cnt[c];
    sort(s.begin(), s.end(), [&](char a, char b) {
        return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
      });
    return s;
  }
};
