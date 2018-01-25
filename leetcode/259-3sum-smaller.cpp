class Solution
{
 public:
  int threeSumSmaller(vector<int>& nums, int target)
  {
    int cnt = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int k = 0; k < n - 2; ++k) {
      for (int i = k + 1, j = n - 1; i < j;)
        if (nums[i] + nums[k] + nums[j] < target)
          cnt += j - i, ++i;
        else
          --j;
    }
    return cnt;
  }
};
