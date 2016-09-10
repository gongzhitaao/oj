class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        :type size: int
        """
        self._nums = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self._nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        nums = self._nums[:]
        n = len(nums)
        for i in range(n):
            j = random.randint(i, n-1)
            if j != i:
                nums[i], nums[j] = nums[j], nums[i]
        return nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
