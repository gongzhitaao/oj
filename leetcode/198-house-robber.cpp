class Solution
{
 public:
  int rob(vector<int>& nums)
  {
    int n3 = 0, n2 = 0, n1 = 0;
    int ret = 0;
    for (int n : nums) {
      int cur = max(n3, n2) + n;
      if (cur > ret) ret = cur;
      n3 = n2, n2 = n1, n1 = cur;
    }
    return ret;
  }
};
