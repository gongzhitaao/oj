class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        null = False
        finish = False
        cnt = []
        for c in preorder + ',':
            if ',' == c:
                if not null: cnt += [0]
                null = False
            else:
                if finish: return False
                if '#' == c:
                    null = True
                    while len(cnt) > 0:
                        cnt[-1] += 1
                        if (2 == cnt[-1]): cnt.pop()
                        else: break
                    finish = len(cnt) == 0
        return len(cnt) == 0
