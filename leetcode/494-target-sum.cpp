class Solution
{
 public:
  int findTargetSumWays(vector<int>& nums, int S)
  {
    unordered_map<int, int> sumcnt;

    if (nums.empty()) return 0;
    ++sumcnt[-nums[0]];
    ++sumcnt[+nums[0]];

    for (int i = 1; i < nums.size(); ++i) {
      int n = nums[i];
      unordered_map<int, int> tmp;
      for (auto& elm : sumcnt) {
        tmp[elm.first+n] += elm.second;
        tmp[elm.first-n] += elm.second;
      }
      swap(sumcnt, tmp);
    }

    return sumcnt[S];
  }
};
