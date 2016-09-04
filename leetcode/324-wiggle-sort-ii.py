class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # def nth_element(a, k):
        #     def _partition(beg, end, pi):
        #         i, j, k, p = beg, beg, end, a[pi]
        #         while j <= k:
        #             if a[j] < p:
        #                 a[i], a[j] = a[j], a[i]
        #                 j += 1
        #                 i += 1
        #             elif a[j] > p:
        #                 a[j], a[k] = a[k], a[j]
        #                 k -= 1
        #             else:
        #                 j += 1
        #         return i

        #     def _kth_range(beg, end, k):
        #         while beg < end:
        #             pi = _partition(beg, end, random.randint(beg, end))
        #             if k == pi:
        #                 return a[pi]
        #             elif k < pi:
        #                 end = pi - 1
        #             else:
        #                 beg = pi + 1
        #         return a[beg]

        #     return _kth_range(0, len(a)-1, k)

        n = len(nums)
        # m = nth_element(nums, n//2)
        m = sorted(nums)[n//2]

        def idx(i):
            return (1 + 2 * i) % (n | 1)

        i, j, k = 0, 0, n - 1
        while j <= k:
            I, J, K = idx(i), idx(j), idx(k)
            if nums[J] > m:
                nums[I], nums[J] = nums[J], nums[I]
                i += 1
                j += 1
            elif nums[J] < m:
                nums[J], nums[K] = nums[K], nums[J]
                k -= 1
            else:
                j += 1
