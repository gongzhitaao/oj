class Solution {
 public:
  int findkth(vector<int>& A, int a, vector<int>& B, int b, int kth)
  {
    int dummy = numeric_limits<int>::max();
    for (int i = a, j = b, k = kth; /* empty */;k -= k / 2) {
      if (i >= A.size()) return B[j + k - 1];
      if (j >= B.size()) return A[i + k - 1];
      if (1 == k) return min(A[i], B[j]);
      int ka = i + k / 2 - 1 < A.size() ? A[i + k / 2 - 1] : dummy;
      int kb = j + k / 2 - 1 < B.size() ? B[j + k / 2 - 1] : dummy;
      if (ka < kb) i += k / 2;
      else j += k / 2;
    }
  }

  double findMedianSortedArrays(vector<int>& nums1,
                                vector<int>& nums2)
  {
    int len = nums1.size() + nums2.size();
    if (len & 1)
      return findkth(nums1, 0, nums2, 0, len / 2 + 1);
    return (findkth(nums1, 0, nums2, 0, len / 2) +
            findkth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
  }
};
