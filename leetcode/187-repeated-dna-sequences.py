class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ret = []
        cnt = {}
        enc = {'A': 4, 'C': 5, 'G': 6, 'T': 7}
        k = 0
        for i, c in enumerate(s):
            k = ((k << 3) | enc[c]) & 0x3fffffff
            if k & 0x20000000:
                if k in cnt:
                    if 1 == cnt[k]:
                        ret += [s[(i-9):(i+1)]]
                    cnt[k] += 1
                else:
                    cnt[k] = 1
        return ret
