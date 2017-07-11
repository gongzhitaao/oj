class Solution
{
 public:
  int subarraySum(vector<int>& nums, int k)
  {
    int sum = 0, ret = 0;
    map<int, int> cnt;

    for (int n : nums) {
      sum += n;
      if (cnt.find(sum - k) != cnt.end())
        ret += cnt[sum - k];
      ++cnt[sum];
    }

    if (cnt.find(k) != cnt.end())
      ret += cnt[k];

    return ret;
  }
};
