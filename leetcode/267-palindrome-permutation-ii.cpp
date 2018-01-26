class Solution
{
 public:
  vector<string> generatePalindromes(string s)
  {
    unordered_map<char, int> dict;
    int single = 0;
    for (char c : s)
      if (++dict[c] % 2) ++single;
      else --single;

    vector<string> ret;
    if (single > 1) return ret;

    char mid = -1;
    for (auto& e : dict) {
      if (e.second % 2) mid = e.first;
      e.second /= 2;
    }

    dfs(dict, mid, "", s.size() / 2, ret);
    return ret;
  }

  void dfs(unordered_map<char, int>& dict, char mid, string half, int len,
           vector<string>& ret)
  {
    if (half.size() == len) {
      string other_half = half;
      reverse(other_half.begin(), other_half.end());
      if (mid > 0)
        half.push_back(mid);
      return ret.push_back(half + other_half);
    }

    for (auto& e : dict)
      if (e.second > 0) {
        --e.second;
        dfs(dict, mid, half + e.first, len, ret);
        ++e.second;
      }
  }
};
