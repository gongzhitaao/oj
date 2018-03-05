class Solution
{
 public:
  int superPow(int a, vector<int>& b)
  {
    if (1 == a) return 1;
    a %= 1337;
    vector<int> mods(11, 1);
    for (int i = 1; i <= 10; ++i) mods[i] = (a * mods[i - 1]) % 1337;
    return powmod(a, b, (int)b.size() - 1, mods);
  }

  int powmod(int a, vector<int>& b, int p, vector<int>& mods)
  {
    if (0 == p) return mods[b[0]];
    int m = powmod(a, b, p - 1, mods);
    int ret = mods[b[p]];
    for (int i = 0; i < 10; ++i) ret = (ret * m) % 1337;
    return ret;
  }
};
