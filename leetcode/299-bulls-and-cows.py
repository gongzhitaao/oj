class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bull, cow = 0, 0
        cnt = {str(c): 0 for c in range(10)}
        for c0, c1 in zip(secret, guess):
            if c0 == c1:
                bull += 1
            else:
                if cnt[c0] < 0:
                    cow += 1
                if cnt[c1] > 0:
                    cow += 1
                cnt[c0] += 1
                cnt[c1] -= 1
        return '{0}A{1}B'.format(bull, cow)
