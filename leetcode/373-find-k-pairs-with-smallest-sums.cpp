class Solution
{
 public:
  vector<pair<int, int> >
  kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<pair<int, int> > ret;
    if (!n1 || !n2) return ret;

    struct cmp {
      bool operator()(tuple<int, int, int, int>& a,
                      tuple<int, int, int, int>& b)
      { return get<0>(a)+get<1>(a) > get<0>(b)+get<1>(b); }
    };
    priority_queue<tuple<int, int, int, int>,
                   vector<tuple<int, int, int, int> >, cmp> q;

    for (int i = 0; i < nums1.size(); ++i)
      q.push(make_tuple(nums1[i], nums2[0], i, 0));

    for (int i = 0; i < k && q.size(); ++i) {
      auto t = q.top(); q.pop();
      ret.push_back({get<0>(t), get<1>(t)});
      if (get<3>(t)+1 < n2)
        q.push(make_tuple(nums1[get<2>(t)], nums2[get<3>(t)+1],
                          get<2>(t), get<3>(t)+1));
    }
    return ret;
  }
};
