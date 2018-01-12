class Solution
{
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    vector<int> ret;
    deque<int> maxpos;
    for (int i = 0; i < nums.size(); ++i) {
      for (; !maxpos.empty() &&
               (maxpos.back() <= i - k || nums[maxpos.back()] < nums[i]);
           maxpos.pop_back())
        ;
      for (; !maxpos.empty() && maxpos.front() <= i - k; maxpos.pop_front())
        ;
      maxpos.push_back(i);
      if (i >= k - 1) ret.push_back(nums[maxpos.front()]);
    }
    return ret;
  }
};
