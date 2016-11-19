class Solution
{
 public:
  int findPeakElement(vector<int>& nums)
  {
    int n = nums.size(), left = INT_MIN;
    for (int i = 0; i < n; left = nums[i++]) {
      if (left < nums[i] && (i+1 == n || nums[i] > nums[i+1]))
        return i;
    }
    return 0;
  }
};
