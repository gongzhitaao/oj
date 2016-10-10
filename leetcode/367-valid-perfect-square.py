class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        i, end = 1, num
        while i <= end:
            if i * i == num:
                return True
            i += 1
            end = int(num / i)
        return False
