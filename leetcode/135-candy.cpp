class Solution
{
 public:
  int candy(vector<int>& ratings)
  {
    if (ratings.empty())
      return 0;

    const int n = ratings.size();
    vector<int> cnt(n, 1);
    for (int i = 1; i < n; ++i)
      if (ratings[i] > ratings[i-1])
        cnt[i] = cnt[i-1] + 1;
    for (int i = n-2; i >= 0; --i)
      if (ratings[i] > ratings[i+1] &&
          cnt[i+1] >= cnt[i])
        cnt[i] = cnt[i+1] + 1;

    return accumulate(cnt.begin(), cnt.end(), 0);
  }
};
