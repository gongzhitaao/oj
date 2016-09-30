class Solution {
 public:
  int kth(vector<int>& A, int a, vector<int>& B, int b, int k)
  {
    if (a >= A.size()) return B[b + k - 1];
    if (b >= B.size()) return A[a + k - 1];
    if (1 == k) return min(A[a], B[b]);
    int ka = a + k / 2 - 1 < A.size()
                             ? A[a + k / 2 - 1]
                             : numeric_limits<int>::max();
    int kb = b + k / 2 - 1 < B.size()
                             ? B[b + k / 2 - 1]
                             : numeric_limits<int>::max();
    if (ka < kb) return kth(A, a + k / 2, B, b, k - k / 2);
    return kth(A, a, B, b + k / 2, k - k / 2);
  }

  double findMedianSortedArrays(vector<int>& nums1,
                                vector<int>& nums2)
  {
    int len = nums1.size() + nums2.size();
    if (len & 1)
      return kth(nums1, 0, nums2, 0, len / 2 + 1);
    return (kth(nums1, 0, nums2, 0, len / 2) +
            kth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
  }
};
