class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""

        ret = ""
        i = 0
        while True:
            if len(strs[0]) == i:
                break

            c = strs[0][i]
            for s in strs[1:]:
                if len(s) == i or s[i] != c:
                    i = -1
                    break

            if i >= 0: ret += c
            else: break

            i += 1

        return ret
