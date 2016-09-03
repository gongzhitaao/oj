class Solution
{
 public:
  string getHint(string secret, string guess)
  {
    int bull = 0, cow = 0;
    vector<int> cnt(10, 0);
    for (int i = 0; i < secret.size(); ++i) {
      int c0 = secret[i] - '0', c1 = guess[i] - '0';
      if (c0 == c1) ++bull;
      else {
        cow += (cnt[c0] < 0) + (cnt[c1] > 0);
        ++cnt[c0], --cnt[c1];
      }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
  }
};
