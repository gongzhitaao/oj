class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l, cnt = 0, len(nums)
        while cnt > 0:
            step = cnt / 2
            m = l + step
            if nums[m] < target:
                l = m + 1
                cnt -= step + 1
            else:
                cnt = step
        return l
