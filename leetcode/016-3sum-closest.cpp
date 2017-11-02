class Solution
{
 public:
  int threeSumClosest(vector<int>& nums, int target)
  {
    sort(nums.begin(), nums.end());
    int diff = numeric_limits<int>::max();

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1, k = nums.size() - 1; j < k; ) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < target) {
          if (target - sum < abs(diff))
            diff = sum - target;
          ++j;
        } else if (sum > target) {
          if (sum - target < abs(diff))
            diff = sum - target;
          --k;
        } else return target;
      }
    }

    return target + diff;  // assume we always have at least three numbers
  }
};
