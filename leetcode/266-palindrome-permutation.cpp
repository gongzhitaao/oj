class Solution
{
 public:
  bool canPermutePalindrome(string s)
  {
    vector<int> cnt(257, 0);
    for (char c : s)
      cnt[c] = 1 - cnt[c];
    for (int i = 0, sum = 0; i < 257; ++i) {
      sum += cnt[i];
      if (sum > 1) return false;
    }
    return true;
  }
};
