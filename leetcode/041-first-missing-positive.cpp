class Solution
{
 public:
  int firstMissingPositive(vector<int>& nums)
  {
    const int n = nums.size();
    for (int i = 0, j = n - 1; i <= j;) {
      if (nums[i] >= n)
        swap(nums[i], nums[j--]);
      else if (nums[i] <= 0 || nums[i] == i + 1 || nums[i] == nums[nums[i] - 1])
        ++i;
      else
        swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < n; ++i)
      if (nums[i] != i + 1) return i + 1;

    return n + 1;
  }
};
