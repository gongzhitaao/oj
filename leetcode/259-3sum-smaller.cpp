class Solution
{
 public:
  int threeSumSmaller(vector<int>& nums, int target)
  {
    sort(nums.begin(), nums.end());
    int cnt = 0, end = nums.size();
    for (int i = 0; i < end; ++i) {
      for (int j = i+1, k = end - 1; j < k; ) {
        if (nums[i]+nums[j]+nums[k] < target)
          cnt += k - j++;
        else --k;
      }
    }
    return cnt;
  }
};
