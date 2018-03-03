class Solution
{
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
  {
    unordered_map<int, int> cnt1, cnt2;
    for (int n : nums1) ++cnt1[n];
    for (int n : nums2) ++cnt2[n];
    vector<int> ret;
    for (auto& kv : cnt1) {
      auto it = cnt2.find(kv.first);
      if (it != cnt2.end())
        for (int i = 0; i < min(kv.second, it->second); ++i)
          ret.push_back(kv.first);
    }
    return ret;
  }
};
