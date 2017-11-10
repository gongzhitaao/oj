class Solution
{
 public:
  int missingNumber(vector<int>& nums)
  {
    int sum = 0;
    for (int i : nums) sum += i;
    return (1 + nums.size()) * nums.size() / 2 - sum;
  }
};
