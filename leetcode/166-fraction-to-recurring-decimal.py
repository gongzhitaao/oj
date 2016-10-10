class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        num, den = numerator, denominator
        symb = '-' if ((num>>31)^(den>>31)) and num else ''

        num, den = abs(num), abs(den)

        rem = num % den
        num = int(num / den)
        inte = str(num)

        frac = ''
        rems = {}
        p = 0
        while rem and rem not in rems:
            rems[rem] = p
            num = rem * 10
            rem = (num % den)
            num = int(num / den)
            p += 1
            frac += str(num)

        if len(rems) > 0:
            if rem > 0:
                p = rems[rem]
                frac = frac[:p] + '(' + frac[p:] + ')'
            frac = '.' + frac
        return symb + inte + frac
