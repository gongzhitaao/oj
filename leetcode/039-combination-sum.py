class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def dfs(cands, i0, target, ret, sol):
            if 0 > target:
                return
            if 0 == target:
                ret += [sol[:]]
                return
            for i in range(i0, len(cands)):
                dfs(cands, i, target-cands[i], ret, sol+[cands[i]])

        ret = []
        dfs(candidates, 0, target, ret, [])
        return ret
