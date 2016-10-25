class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if k <= 0: return 0

        n = len(s)
        if k >= n: return n;

        record = {}
        start, end = 0, 0
        ret = 0
        while end < n:
            c = s[end]
            if c not in record:
                record[c] = 0
            record[c] += 1
            while len(record) > k:
                c = s[start]
                record[c] -= 1
                if 0 == record[c]:
                    del record[c]
                start += 1
            if end - start + 1 > ret:
                ret = end - start + 1
            end += 1
        return ret
