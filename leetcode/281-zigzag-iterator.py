class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        v = [v1, v2]
        l = [len(v1), len(v2)]
        i = [0, 0]

        j, k = 0, 0
        self._v = [0] * (l[0]+l[1])
        while i[0] < l[0] and i[1] < l[1]:
          self._v[k] = v[j][i[j]]
          i[j] += 1
          k += 1
          j = 1 - j
        while i[0] < l[0]:
          self._v[k] = v[0][i[0]]
          k += 1
          i[0] += 1
        while i[1] < l[1]:
          self._v[k] = v[1][i[1]]
          k += 1
          i[1] += 1

        self._i = 0

    def next(self):
        """
        :rtype: int
        """
        val = self._v[self._i]
        self._i += 1
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._i < len(self._v)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
