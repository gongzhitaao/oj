class Solution
{
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums)
  {
    int n = nums.size();
    if (0 == n) return {};

    sort(nums.begin(), nums.end());
    vector<vector<int>> v(n, vector<int>());

    int maxcnt = 1, maxpos = 0;
    v[0].push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
      int pos = -1;
      for (int j = 0, cnt = 0; j < i; ++j) {
        if (0 == nums[i] % nums[j] && v[j].size() > cnt)
          cnt = v[j].size(), pos = j;
      }
      if (pos >= 0) {
        v[i] = v[pos];
        if (v[i].size() >= maxcnt)
          maxcnt = v[i].size() + 1, maxpos = i;
      }
      v[i].push_back(nums[i]);
    }

    return v[maxpos];
  }
};
