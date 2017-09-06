class Solution
{
 public:
  string longestPalindrome(string s)
  {
    const int n = s.size();
    int maxc = 1;
    vector<int> p(2 * n + 1, 0);
    p[1] = 2;

    for (int i = 2, c = 1; i < 2 * n; ++i) {
      // mirror position of i w.r.t center c
      int j = 2 * c - i;
      // left boundary of palindrome centered at c
      int k = 2 * c - p[c];

      if (i <= p[c] && 2 * j - p[j] > k) {
        p[i] = 2 * (c - j) + p[j];
      } else {
        k = max(p[c] + 1, i + 1);
        k += 1 - (k & 1);
        for (; k < 2 * n && 2 * i - k >= 0 &&
                 s[k / 2] == s[(2 * i - k) / 2];
             k += 2) ;
        p[i] = --k;
        if (k > p[c])
          c = i;
      }

      if (p[i] - i > p[maxc] - maxc)
        maxc = i;
    }

    return s.substr((2 * maxc - p[maxc]) / 2, p[maxc] - maxc);
  }
};
