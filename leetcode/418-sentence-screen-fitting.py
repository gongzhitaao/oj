class Solution(object):
  def wordsTyping(self, sentence, rows, cols):
    """
    :type sentence: List[str]
    :type rows: int
    :type cols: int
    :rtype: int
    """
    words = ' '.join(sentence)
    L = len(words)
    ind, cnt = 0, 0
    while rows > 0:
      if ind+cols < L:
        ind += cols
      else:
        cnt += 1
        suffix_len = L - ind
        room = cols - suffix_len
        tmp = int(room / (L+1.))
        cnt += tmp
        ind = cols - tmp*(L+1) - suffix_len - 1

      while ind >= 0 and ' ' != words[ind]:
        ind -= 1
      ind += 1

      rows -= 1
    return cnt
