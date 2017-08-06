class Solution
{
 public:
  vector<int> twoSum(vector<int>& numbers, int target)
  {
    for (int i = 0, j = numbers.size()-1, sum; i < j; ) {
      sum = numbers[i] + numbers[j];
      if (sum == target) return {i+1, j+1};
      if (sum < target) ++i;
      else --j;
    }
    return {0, 0};
  }
};
