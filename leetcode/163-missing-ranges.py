class Solution(object):
  def findMissingRanges(self, nums, lower, upper):
    """
    :type nums: List[int]
    :type lower: int
    :type upper: int
    :rtype: List[str]
    """
    ret = []
    nums += [upper+1]
    start = lower - 1
    for num in nums:
      if start+1 < num:
        end = num - 1
        if start+1 == end:
          ret += ['{0}'.format(end)]
        else:
          ret += ['{0}->{1}'.format(start+1, end)]
      start = num
    return ret
