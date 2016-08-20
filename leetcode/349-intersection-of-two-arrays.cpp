class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    unordered_map<int, bool> picked;
    for (int n : nums1) picked[n] = false;

    vector<int> ret;
    for (int n : nums2) {
      if (picked.find(n) != picked.end() && !picked[n]) {
        ret.push_back(n);
        picked[n] = true;
      }
    }

    return ret;
  }
};
