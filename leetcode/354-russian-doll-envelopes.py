class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        def lower_bound(a, k, comp=operator.lt):
            l, cnt = 0, len(a)
            while cnt > 0:
                step = cnt / 2
                m = l + step
                if comp(a[m], k):
                    l = m + 1
                    cnt -= step + 1
                else:
                    cnt = step
            return l

        envelopes.sort(
            lambda a, b: b[1] - a[1] if a[0] == b[0] else a[0] - b[0])

        lis  = []
        for e in envelopes:
            p = lower_bound(lis, e[1])
            if p == len(lis):
                lis.append(e[1])
            else:
                lis[p] = e[1]
        return len(lis)
