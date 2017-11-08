class Solution
{
 public:
  string getPermutation(int n, int k)
  {
    string s(n, 0);

    int cnt = 1;
    for (int i = 1; i <= n; cnt *= i++) s[i - 1] = i + '0';

    --k;
    for (int i = 0; i < n; ++i, k %= cnt) {
      cnt /= n - i;
      int m = k / cnt;
      nth_element(s.begin() + i, s.begin() + i + m, s.end());
      if (m) swap(s[i], s[i + m]);
    }

    return s;
  }
};
