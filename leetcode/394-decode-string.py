class Solution(object):
  def decodeString(self, s):
    """
    :type s: str
    :rtype: str
    """
    part = []
    cnt = []
    n = 0
    ans = ''
    s = '1[{0}]'.format(s)
    for ch in s:
      if ch.isdigit():
        n = n*10 + ord(ch)-ord('0')
      elif '[' == ch:
        cnt.append(n)
        n = 0
        part.append(ans)
        ans = ''
      elif ']' == ch:
        ans = part.pop() + ans*cnt.pop()
      else:
        ans += ch
    return ans
