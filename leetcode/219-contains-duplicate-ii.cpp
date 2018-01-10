class Solution
{
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k)
  {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      int n = nums[i];
      if (m.find(n) != m.end() && i - m[n] <= k) return true;
      m[n] = i;
    }
    return false;
  }
};
