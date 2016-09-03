class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if 0 == len(s):
            return 0

        a = 1
        b = 1 if s[0] != '0' else 0
        for i in range(1, len(s)):
            n0 = int(s[i])
            n1 = int(s[i-1:i+1])

            c = 0
            if 0 < n0: c += b
            if 9 < n1 and n1 < 27: c += a

            a = b
            b = c

        return b
