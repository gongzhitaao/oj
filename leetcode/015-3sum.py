class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        size = len(nums)
        ret = {}
        a = None
        for i in range(size - 2):
            if a is not None and a == nums[i]: continue
            a = nums[i]
            j, k = i + 1, size - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if 0 == s:
                    key = (nums[i], nums[j], nums[k])
                    ret[key] = list(key)
                    j += 1
                    k -= 1
                elif s > 0:
                    k -= 1
                else:
                    j += 1
        return ret.values()
