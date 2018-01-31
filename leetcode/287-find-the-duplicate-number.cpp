class Solution
{
 public:
  int findDuplicate(vector<int>& nums)
  {
    int lo = 1, hi = nums.size();
    for (int mi; lo < hi; ) {
      mi = lo + (hi - lo) / 2;
      int cnt = 0;
      for (int n : nums)
        if (n <= mi) ++cnt;
      if (cnt <= mi) lo = mi + 1;
      else hi = mi;
    }
    return lo;
  }

};
