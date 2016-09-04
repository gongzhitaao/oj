"""Find median in linear time."""

import random


def nth_element(a, k):
    def _partition(beg, end, pi):
        i, j, k, p = beg, beg, end, a[pi]
        while j <= k:
            if a[j] < p:
                a[i], a[j] = a[j], a[i]
                j += 1
                i += 1
            elif a[j] > p:
                a[j], a[k] = a[k], a[j]
                k -= 1
            else:
                j += 1
        return i

    def _kth_range(beg, end, k):
        while beg < end:
            pi = _partition(beg, end, random.randint(beg, end))
            if k == pi:
                return a[pi]
            elif k < pi:
                end = pi - 1
            else:
                beg = pi + 1
        return a[beg]

    return _kth_range(0, len(a)-1, k)


if __name__ == '__main__':
    for i in range(1000):
        n = random.randint(1, 20)
        seq = range(10)
        a = [random.choice(seq) for _ in range(n)]
        m0 = nth_element(a, n//2)
        m1 = sorted(a)[n//2]
        if m1 != m0:
            print("Fail!! m0={0} m1={1}".format(m0, m1))
            print(sorted(a))
            break
