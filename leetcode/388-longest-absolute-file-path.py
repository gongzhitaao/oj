class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        maxlen = 0
        stk = [0]
        curlev, isfile, cnt = 0, 0, 0
        for c in input+'\n':
            if '\n' == c:
                while len(stk) > curlev + 1:
                    stk.pop()
                stk.append(cnt + stk[-1])
                if isfile:
                    isfile = 0
                    if stk[-1] + curlev > maxlen:
                        maxlen = stk[-1] + curlev
                curlev = 0
                cnt = 0
            elif '\t' == c:
                curlev += 1
            else:
                cnt += 1
                if '.' == c:
                    isfile = 1
        return maxlen
