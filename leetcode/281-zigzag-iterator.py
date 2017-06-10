class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self._data = (v[i]
                      for i in itertools.count()
                      for v in (v1, v2)
                      if i < len(v))
        self._n = len(v1) + len(v2)

    def next(self):
        """
        :rtype: int
        """
        self._n -= 1
        return next(self._data)

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._n > 0

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
