class Solution
{
 public:
  bool increasingTriplet(vector<int>& nums)
  {
    int m0 = numeric_limits<int>::max(),
        m1 = numeric_limits<int>::max();

    for (int n : nums) {
      if (n <= m0) m0 = n;
      else if (n <= m1) m1 = n;
      else return true;
    }

    return false;
  }
};
