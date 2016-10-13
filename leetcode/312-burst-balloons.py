class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums);
        if 0 == n: return 0
        if 1 == n: return nums[0]

        A = [1] + nums + [1]
        v = [[-sys.maxsize]*i + [0,0] + [-sys.maxsize]*(n-i)
             for i in range(n+1)]
        for i in range(n-1, -1, -1):
            for j in range(i+2, n+2):
                for k in range(i+1, j):
                    v[i][j] = max(v[i][j],
                                  v[i][k] + v[k][j] + A[i]*A[k]*A[j])
        return v[0][n+1]
