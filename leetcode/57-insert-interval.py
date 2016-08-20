# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        ret = []
        inserted = False
        newitv = newInterval
        for itv in intervals:
            if inserted:
                ret += [itv]
            else:
                if newitv.end < itv.start:
                    inserted = True
                    ret += [newitv, itv]
                elif newitv.start > itv.end:
                    ret += [itv]
                else:
                    newitv.start = min(newitv.start, itv.start)
                    newitv.end = max(newitv.end, itv.end)

        if not inserted:
            ret += [newitv]

        return ret
