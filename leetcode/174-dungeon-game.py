class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        n, m = len(dungeon), len(dungeon[0])
        hp = [sys.maxsize] * (m + 1)
        hp[-2] = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                hp[j] = max(min(hp[j + 1], hp[j]) - dungeon[i][j], 1)
        return hp[0]
