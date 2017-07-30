class Solution {
public:
  int uniquePaths(int m, int n) {
    int large, small;
    if (m > n) large = m, small = n;
    else large = n, small = m;

    int cnt[large + 1];
    fill(cnt, cnt + large + 1, 0);
    cnt[1] = 1;

    for (int i = 1; i <= small; ++i)
      for (int j = 1; j <= large; ++j)
        cnt[j] += cnt[j - 1];

    return cnt[large];
  }
};
