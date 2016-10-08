class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        def kth_element(k, A, B):
            n, m = len(A), len(B)

            if n < m:
                return kth_element(k, B, A)

            imax, imin = sys.maxsize, -sys.maxsize

            if k >= n + m:
                return max(A[-1] if n > 0 else imin,
                           B[-1] if m > 0 else imin)

            l, h = 0, min(k, m-1)
            while l <= h:
                m2 = l + ((h - l) >> 1)
                m1 = k - m2
                L1 = A[m1 - 1] if m1 > 0 else imin
                R1 = A[m1] if m1 < n else imax
                L2 = B[m2 - 1] if m2 > 0 else imin
                R2 = B[m2]
                if L1 > R2:
                    l = m2 + 1
                elif L2 > R1:
                    h = m2 - 1
                else:
                    return min(R1, R2)

            return A[k - m]

        n = len(nums1) + len(nums2)
        if n & 1:
            return kth_element(n>>1, nums1, nums2)
        else:
            return (kth_element((n>>1) - 1, nums1, nums2) +
                    kth_element((n>>1), nums1, nums2)) / 2.
