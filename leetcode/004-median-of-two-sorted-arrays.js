/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
  function kth_element(k, A, B) {
    var n = A.length, m = B.length;
    if (n < m) return kth_element(k, B, A);

    var imin = Number.MIN_SAFE_INTEGER,
        imax = Number.MAX_SAFE_INTEGER;

    if (k >= n + m)
      return Math.max(n > 0 ? A[n - 1] : imin,
                      m > 0 ? B[m - 1] : imin);

    var l, h, m1, m2, L1, R1, L2, R2;
    for (l = 0, h = Math.min(k, m - 1); l <= h; ) {
      m2 = l + Math.floor((h - l) / 2);
      m1 = k - m2;
      L1 = m1 > 0 ? A[m1 - 1] : imin;
      R1 = m1 < n ? A[m1] : imax;
      L2 = m2 > 0 ? B[m2 - 1] : imin;
      R2 = B[m2];
      if (L1 > R2) l = m2 + 1;
      else if (L2 > R1) h = m2 - 1;
      else return Math.min(R1, R2);
    }

    return A[k - m];
  }

  var n = nums1.length + nums2.length;
  if (n & 1)
    return kth_element(Math.floor(n / 2), nums1, nums2);
  else
    return (kth_element(Math.floor(n / 2), nums1, nums2) +
            kth_element(Math.floor(n / 2) - 1, nums1, nums2)) / 2.0;
};
