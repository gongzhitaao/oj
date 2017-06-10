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
    pos = [0] * L

    p = 0
    for i in range(L):
      if ' ' == words[i]:
        p = i + 1
      pos[i] = p

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

      ind = 0 if ind < 0 else pos[ind]

      rows -= 1
    return cnt
