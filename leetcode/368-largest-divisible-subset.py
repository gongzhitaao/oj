class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        if 0 == n:
            return []

        nums.sort()

        maxcnt, maxpos = 1, 0
        v = [[nums[i]] for i in range(n)]
        for i in range(1, n):
            cnt, pos = 0, -1
            for j in range(i):
                if 0 == nums[i] % nums[j] and len(v[j]) > cnt:
                    cnt, pos = len(v[j]), j
            if pos >= 0:
                v[i] += v[pos]
                if len(v[i]) > maxcnt:
                    maxcnt, maxpos = len(v[i]), i

        return v[maxpos]
