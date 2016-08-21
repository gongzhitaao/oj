# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, h = 1, n
        while l <= h:
            if 0 == guess(l):
                return l
            if 0 == guess(h):
                return h
            m = l + (h - l) / 2
            g = guess(m)
            if 0 == g:
                break
            elif g > 0:
                l = m + 1
                h -= 1
            else:
                h = m - 1
                l += 1
        return m
