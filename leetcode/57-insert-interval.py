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
        if 0 == len(intervals):
            return [newInterval]

        merging = -1
        start = None

        ret = []
        for itv in intervals:
            if merging < 0:
                if newInterval.end < itv.start:
                    merging = 1
                    ret += [newInterval, itv]
                elif newInterval.end <= itv.end:
                    merging = 1
                    start = min(newInterval.start, itv.start)
                    ret += [Interval(start, itv.end)]
                elif newInterval.start <= itv.end:
                    merging = 0
                    start = min(newInterval.start, itv.start)
                else:
                    ret += [itv]
            elif 0 == merging:
                if newInterval.end < itv.start:
                    merging = 1
                    ret += [Interval(start, newInterval.end), itv]
                elif newInterval.end <= itv.end:
                    merging = 1
                    ret += [Interval(start, itv.end)]
            else: # merging > 0
                ret += [itv]

        if merging < 0:
            ret += [newInterval]
        elif 0 == merging:
            ret += [Interval(start, newInterval.end)]

        return ret
