class Solution
{
 public:
  vector<pair<int, int> >
  kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  {
    vector<pair<int, int> > ret;
    for (int n1 : nums1)
      for (int n2 : nums2)
        ret.push_back({n1, n2});
    sort(ret.begin(), ret.end(),
         [](pair<int, int>& a, pair<int, int>& b)
         { return a.first+a.second < b.first+b.second; });
    if (k >= ret.size()) return ret;
    return vector<pair<int, int> >(ret.begin(), ret.begin()+k);
  }
};
