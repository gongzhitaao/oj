class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        n, m = len(t), len(s)
        d = [[0] * (m+1) for _ in range(n+1)]
        d[0] = [1] * (m+1)
        for i in range(1, n+1):
            for j in range(i, m+1):
                d[i][j] = d[i][j-1]
                if (t[i-1] == s[j-1]):
                    d[i][j] += d[i-1][j-1]
        return d[n][m]
