class Solution
{
 public:
  vector<pair<int, int> >
  kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  {
    struct cmp {
      bool operator() (pair<int, int>& a, pair<int, int>& b)
      { return a.first+a.second > b.first+b.second; };
    };

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    for (int n1 : nums1)
      for (int n2 : nums2)
        q.push({n1, n2});
    vector<pair<int, int> > ret;
    for (int i = 0; i < k && q.size(); ++i) {
      ret.push_back(q.top());
      q.pop();
    }
    return ret;
  }
};
