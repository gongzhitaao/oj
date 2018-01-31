class Solution
{
 public:
  int findDuplicate(vector<int>& nums)
  {
    if (nums.size() < 2) return nums[0];

    int slow = nums[0], fast = nums[nums[0]];
    for (; slow != fast; slow = nums[slow], fast = nums[nums[fast]])
      ;

    for (slow = 0; slow != fast; slow = nums[slow], fast = nums[fast])
      ;

    return slow;
  }
};
