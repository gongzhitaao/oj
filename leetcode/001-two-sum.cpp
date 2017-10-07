class Solution
{
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    const int n = nums.size();
    if (0 == n) return {};

    unordered_map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) pos[nums[i]].push_back(i);

    for (int i = 0; i < n; ++i) {
      int k = target - nums[i];

      auto it = pos.find(k);
      if (it == pos.end()) continue;

      if (k == nums[i]) {
        if (it->second.size() > 1) return it->second;
      } else
        return {i, it->second[0]};
    }

    return {};
  }
};
