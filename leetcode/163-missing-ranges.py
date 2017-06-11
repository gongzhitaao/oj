class Solution(object):
  def findMissingRanges(self, nums, lower, upper):
    """
    :type nums: List[int]
    :type lower: int
    :type upper: int
    :rtype: List[str]
    """
    ret = []
    pre = lower - 1
    start = lower
    for num in nums:
      if pre == num:
        continue
      pre = num
      if start != num:
        end = num - 1
        if start == end:
          ret += ['{0}'.format(start)]
        else:
          ret += ['{0}->{1}'.format(start, end)]
      start = num + 1
    if start < upper:
      ret += ['{0}->{1}'.format(start, upper)]
    elif start == upper:
      ret += ['{0}'.format(start)]
    return ret
