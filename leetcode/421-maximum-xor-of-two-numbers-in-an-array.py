class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for i in range(30, -1, -1):
            ans <<= 1
            prefix = {n>>i: 0 for n in nums}
            ans |= any(ans^1^p in prefix for p in prefix)
        return ans
