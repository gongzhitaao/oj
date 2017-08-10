class Solution
{
 public:
  vector<int> countBits(int num)
  {
    vector<int> cnt(num+1, 0);
    for (int i = 1; i <= num; ++i)
      cnt[i] = (i & 1) + cnt[i >> 1];
    return cnt;
  }
};
