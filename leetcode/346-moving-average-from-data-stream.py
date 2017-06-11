class MovingAverage(object):

  def __init__(self, size):
    """
    Initialize your data structure here.
    :type size: int
    """
    self._data = []
    self._size = size

  def next(self, val):
    """
    :type val: int
    :rtype: float
    """
    self._data += [val]
    if len(self._data) > self._size:
      self._data = self._data[1:]
    return 1.0 * sum(self._data) / len(self._data)



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
