class Solution
{
 public:
  bool find132pattern(vector<int>& nums)
  {
    const int n = nums.size();
    stack<int> stk;

    for (int i = n - 1, s3 = -1; i >= 0; --i) {
      if (s3 >= 0 && nums[i] < nums[s3])
        return true;

      for (; stk.size() && nums[i] > nums[stk.top()]; stk.pop())
        if (s3 < 0 || nums[stk.top()] > nums[s3])
          s3 = stk.top();

      stk.push(i);
    }

    return false;
  }
};
