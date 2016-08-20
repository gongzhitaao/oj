class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        picked = {}
        for n in nums1:
            picked[n] = False

        ret = []
        for n in nums2:
            if n in picked and not picked[n]:
                picked[n] = True
                ret.append(n)

        return ret
