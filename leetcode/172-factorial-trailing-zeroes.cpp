class Solution {
public:
  int trailingZeroes(int n) {
    int cnt = 0;
    for (long long s = 5; n / s > 0; s *= 5)
      cnt += n / s;
    return cnt;
  }
};
