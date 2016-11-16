class Solution
{
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    vector<int> ret;
    deque<pair<int, int> > q;
    for (int i = 0; i < nums.size(); ++i) {
      while (!q.empty() && q.front().first <= nums[i])
        q.pop_front();
      q.push_front({nums[i], i});
      if (i-q.back().second >= k)
        q.pop_back();
      if (i >= k-1) ret.push_back(q.back().first);
    }
    return ret;
  }
};
