class Solution {
 public:
  int kth_element(int k, vector<int>& A, vector<int>& B)
  {
    if (A.size() < B.size()) return kth_element(k, B, A);
    if (k >= A.size() + B.size()) return max(A.back(), B.back());
    int imin = numeric_limits<int>::min(),
        imax = numeric_limits<int>::max();
    for (int l = 0, h = min(int(B.size() - 1), k); l <= h; ) {
      int m2 = l + (h - l) / 2;
      int m1 = k - m2;
      int L1 = m1 > 0 ? A[m1 - 1] : imin;
      int R1 = m1 < A.size() ? A[m1] : imax;
      int L2 = m2 > 0 ? B[m2 - 1] : imin;
      int R2 = B[m2];
      if (L1 > R2) l = m2 + 1;
      else if (L2 > R1) h = m2 - 1;
      else return min(R1, R2);
    }
    return A[k - B.size()];
  }

  double findMedianSortedArrays(vector<int>& nums1,
                                vector<int>& nums2)
  {
    int len = nums1.size() + nums2.size();
    if (len & 1)
      return kth_element(len / 2, nums1, nums2);
    return (kth_element(len / 2 - 1, nums1, nums2) +
            kth_element(len / 2, nums1, nums2)) / 2.0;
  }
};
