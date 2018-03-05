class Solution
{
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                        int k)
  {
    if (nums1.empty() || nums2.empty()) return {};
    typedef pair<int, int> pair_t;
    const int n1 = nums1.size(), n2 = nums2.size();
    auto cmp = [&nums1, &nums2](pair_t& a, pair_t& b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair_t, vector<pair_t>, decltype(cmp)> q(cmp);
    for (int i = 0; i < n1; ++i) q.push({i, 0});
    vector<pair_t> ret;
    int end = min(n1 * n2, k);
    for (int i = 0; i < end; ++i) {
      pair_t j = q.top();
      q.pop();
      ret.push_back({nums1[j.first], nums2[j.second]});
      if (j.second + 1 < n2) q.push({j.first, j.second + 1});
    }
    return ret;
  }
};
