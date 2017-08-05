class Solution
{
 public:
  bool checkSubarraySum(vector<int>& nums, int k)
  {
    int n = nums.size();
    if (n < 2) return false;

    k = abs(k);
    if (1 == k) return true;

    if (0 == k) {
      for (int i = 1; i < n; ++i)
        if (0 == nums[i-1] + nums[i])
          return true;
      return false;
    }

    unordered_map<int, int> pos;
    pos[nums[0] % k] = 0;

    for (int i = 1, sum = nums[0]; i < n; ++i) {
      sum += nums[i];
      int r = sum % k;
      if (0 == r) return true;
      if (pos.find(r) == pos.end())
        pos[r] = i;
      else if (i - pos[r] >= 1)
        return true;
    }

    return false;
  }
};
