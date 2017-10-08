class Solution
{
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
  {
    int i, j, k;
    for (k = m + n - 1, i = m - 1, j = n - 1; k >= 0 && i >= 0 && j >= 0; --k) {
      if (nums1[i] > nums2[j]) nums1[k] = nums1[i--];
      else nums1[k] = nums2[j--];
    }
    for (; j >= 0; --k, --j)
      nums1[k] = nums2[j];
  }
};
