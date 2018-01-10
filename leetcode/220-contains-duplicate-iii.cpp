class Solution
{
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
  {
    if (t < 0 || k <= 0) return false;

    multiset<long long> lastk;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k) lastk.erase(nums[i - k - 1]);

      auto lo = lastk.upper_bound((long long)nums[i] - t - 1);
      auto hi = lastk.upper_bound((long long)nums[i] + t);
      if (distance(lo, hi)) return true;

      lastk.insert(nums[i]);
    }

    return false;
  }
};
