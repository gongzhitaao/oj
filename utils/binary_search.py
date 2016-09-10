import operator


def upper_bound(a, k, comp=operator.lt):
    l, cnt = 0, len(a)
    while cnt > 0:
        step = cnt / 2
        m = l + step
        if not comp(k, a[m]):
            l = m + 1
            cnt -= step + 1
        else:
            cnt = step
    return l


def lower_bound(a, k, comp=operator.lt):
    l, cnt = 0, len(a)
    while cnt > 0:
        step = cnt / 2
        m = l + step
        if comp(a[m], k):
            l = m + 1
            cnt -= step + 1
        else:
            cnt = step
    return l
