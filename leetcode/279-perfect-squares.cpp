class Solution
{
 public:
  int numSquares(int n)
  {
    vector<int> cnt{0};
    while (cnt.size() <= n) {
      int m = cnt.size();
      int mincnt = numeric_limits<int>::max();
      for (int i = 1; i*i <= m; ++i)
        mincnt = min(mincnt, cnt[m-i*i]+1);
      cnt.push_back(mincnt);
    }
    return cnt[n];
  }
};
