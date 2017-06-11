class MovingAverage(object):

  def __init__(self, size):
    """
    Initialize your data structure here.
    :type size: int
    """
    self._data = collections.deque(maxlen=size)

  def next(self, val):
    """
    :type val: int
    :rtype: float
    """
    self._data.append(val)
    return 1.0 * sum(self._data) / len(self._data)



# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
