class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m + n - 1, j1 = m - 1, j2 = n - 1; i >= 0; --i) {
      if (j2 < 0) nums1[i] = nums1[j1--];
      else if (j1 < 0) nums1[i] = nums2[j2--];
      else if (nums1[j1] > nums2[j2]) nums1[i] = nums1[j1--];
      else nums1[i] = nums2[j2--];
    }
  }
};
