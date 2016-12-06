class Solution
{
 public:
  string removeDuplicateLetters(string s)
  {
    vector<int> cnt(128, 0);
    vector<bool> v(128, false);
    for (char ch : s) ++cnt[ch];
    string ret = "0";
    for (char ch : s) {
      --cnt[ch];
      if (v[ch]) continue;
      while (ch < ret.back() && cnt[ret.back()]) {
        v[ret.back()] = false;
        ret.pop_back();
      }
      ret += ch;
      v[ch] = true;
    }
    return ret.substr(1);
  }
};
