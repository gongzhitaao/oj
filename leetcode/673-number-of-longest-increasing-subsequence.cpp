class Solution
{
 public:
  int findNumberOfLIS(vector<int>& nums)
  {
    if (nums.empty()) return 0;

    const int n = nums.size();
    vector<int> maxlencnts(n, 1);
    vector<int> maxlens(n, 1);
    int maxlen = 1, cnt = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          if (maxlens[j] + 1 > maxlens[i])
            maxlens[i] = maxlens[j] + 1, maxlencnts[i] = maxlencnts[j];
          else if (maxlens[j] + 1 == maxlens[i])
            maxlencnts[i] += maxlencnts[j];
        }
      }

      if (maxlens[i] > maxlen) {
        maxlen = maxlens[i];
        cnt = maxlencnts[i];
      } else if (maxlens[i] == maxlen)
        cnt += maxlencnts[i];
    }

    return cnt;
  }
};
