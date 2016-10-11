class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        n = len(triangle)
        if 0 == n: return 0

        imax = sys.maxsize
        sums = [0] + [imax] * (n-1)
        for i in range(n):
            p = imax
            for j in range(i+1):
                t = sums[j]
                sums[j] = min(p, sums[j]) + triangle[i][j]
                p = t
        return min(sums)
