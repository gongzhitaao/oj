class Solution
{
 public:
  int findMin(vector<int>& nums)
  {
    int guess = nums[0];
    for (int n : nums)
      if (n < guess) guess = n;
    return guess;
  }
};
