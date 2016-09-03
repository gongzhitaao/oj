class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        jumps, a, b, n = 0, 0, 0, len(nums)
        for i, num in enumerate(nums):
            b = max(num + i, b)
            if a + 1 >= n: break
            if i == a:
                a = b
                jumps += 1
        return jumps
